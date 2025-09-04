// SPDX-License-Identifier: GPL-2.0-only
/*
 * VTX PCM (DMA) Platform Driver
 */

/* ========================================================================== */
/* Compile Option */

#define CFG_PLATFORM_DRIVER  0

//#define OPT_DEBUG_LOCAL // local switch for debug
//#define OPT_DUMP_MMR

#define OPT_DMA_WORKAROUND // allocate & free DMA channel resources per run

#define OPT_DMA_ALLOC  // DMA memory allocation
#define OPT_DMA_DESC_RECYCLE  0 // H/W Recycle or S/W Refill
#define OPT_DMA_DESC_FILL_PROFILE  0 // profile fill desc. time

//#define OPT_TDM_4

/* ========================================================================== */

#include <linux/module.h>
#include <linux/ioctl.h>
#include <linux/delay.h>
#include <linux/init.h>
#include <linux/errno.h>
#include <linux/err.h>
#include <linux/slab.h>
#include <linux/cacheflush.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/mm.h>
#include <linux/irqdomain.h>

// DMA
#include <linux/dma-mapping.h>
#include <linux/dmaengine.h>
#if defined(OPT_DUMP_MMR) || defined(OPT_DEBUG_LOCAL)
#include <linux/dma/leipzig_pdma.h>
#endif

#include <sound/core.h>
#include <sound/soc.h>
#include <sound/pcm_params.h>

// VTX
#include "vtx-asoc.h"
#include "vtx-i2s.h"

/* ========================================================================== */

#define PCM_DRV_NAME  VPL_PLATFORM

/* Version Information*/
#define PCM_MAJOR  1
#define PCM_MINOR  0
#define PCM_BUILD  0
#define PCM_REV    0

#define VPL_PCM_VERSION     MAKEFOURCC(PCM_MAJOR, PCM_MINOR, PCM_BUILD, PCM_REV)
#define VPL_PCM_ID_VERSION  MAKEVERSTR(PCM_MAJOR, PCM_MINOR, PCM_BUILD, PCM_REV)

/* -------------------------------------------------------------------------- */

/* DMA framework */
#ifdef OPT_DEBUG_LOCAL
#define DMADBG(fmt, args...) \
	pr_debug("[ASoC][DMA] %s: " fmt, __func__, ##args)
#else
#define DMADBG(fmt, args...)
#endif

#define DMA_I2S_FIFO_LENGTH  16 // FIFO size = 32-bit Word Size * 16 number
#define DMA_I2S_RX_BURST_LEVEL	16
#define DMA_I2S_TX_BURST_LEVEL	16

/* ========================================================================== */

/* Callback function declaration */
static void _dma_rx_done(void *arg);
static void _dma_tx_done(void *arg);

/* ========================================================================== */

static inline void __iomem *get_dma_ch_base(struct dma_chan *chan)
{
#if defined(OPT_DUMP_MMR) || defined(OPT_DEBUG_LOCAL)
	struct pdma_chan *ch = container_of(chan, struct pdma_chan, chan);

	return ch->regs;
#else
	return NULL;
#endif

}

/* ========================================================================== */

static u64 vtx_pcm_dma_mask = 0xffffffff; // used by framework?

/* ALSA framework variables */
static struct snd_pcm_hardware vtx_pcm_hardware = {
	.info = (SNDRV_PCM_INFO_INTERLEAVED | SNDRV_PCM_INFO_NONINTERLEAVED |
				SNDRV_PCM_INFO_BLOCK_TRANSFER |
				SNDRV_PCM_INFO_MMAP | SNDRV_PCM_INFO_MMAP_VALID),
	/* formats: S16_LE, S32_LE */
	.formats = SNDRV_PCM_FMTBIT_S16_LE | SNDRV_PCM_FMTBIT_S32_LE,
	/* rate: 8 ~ 96 KHz */
	.rates = (SNDRV_PCM_RATE_8000 | SNDRV_PCM_RATE_16000 |
				SNDRV_PCM_RATE_32000 | SNDRV_PCM_RATE_44100 |
				SNDRV_PCM_RATE_96000 |
				SNDRV_PCM_RATE_48000 | SNDRV_PCM_RATE_KNOT),
	.rate_min = 8000,
	.rate_max = 96000,
	/* channel number = 2 */
	.channels_min = 2,
	.channels_max = 2,
	/* period */
	.periods_min = 2,
	.periods_max = 8192,
	.buffer_bytes_max =	1024 * 1024, // 1 MB buffer size
	.period_bytes_min =	128,
	.period_bytes_max =	16380, // ~ 16 KB (16,384)
};

/* ========================================================================== */

static int _dma_buffer_init(struct snd_pcm *pcm, int stream)
{
	struct device *dev = pcm->card->dev;
	struct snd_pcm_substream *substream = pcm->streams[stream].substream;
	struct snd_dma_buffer *buf = &substream->dma_buffer;
	size_t size = vtx_pcm_hardware.buffer_bytes_max;

	DBG("+++\n");
	/* PCM data buffer */
	buf->dev.type = SNDRV_DMA_TYPE_DEV;
	buf->dev.dev = dev;
	buf->private_data = NULL;
#ifdef OPT_DMA_ALLOC
	buf->area = dma_alloc_coherent(dev, size, &buf->addr, GFP_KERNEL);
#else
	buf->area = kmalloc(size, GFP_KERNEL);
	if (buf->area)
		buf->addr = virt_to_phys(buf->area);
#endif
	if (!buf->area) {
		ERR("allocate PCM data buffer failed!(size %zd)\n", size);
		return -ENOMEM;
	}
	buf->bytes = size;

	DBG("---\n");
	return 0;
}

static void _dma_buffer_free(struct snd_pcm *pcm)
{
	struct snd_pcm_substream *substream;
	struct snd_dma_buffer *buf;
	int stream;
#ifdef OPT_DMA_ALLOC
	struct device *dev = pcm->card->dev;
#endif

	for (stream = 0; stream < 2; stream++) {
		substream = pcm->streams[stream].substream;
		if (!substream)
			continue;

		buf = &substream->dma_buffer;
		if (!buf->area)
			continue;
#ifdef OPT_DMA_ALLOC
		dma_free_coherent(dev, buf->bytes, buf->area, buf->addr);
#else
		kfree(buf->area);
#endif
		buf->area = NULL;
	}

}

/* -------------------------------------------------------------------------- */

#ifdef OPT_DMA_WORKAROUND

static int _dma_init(struct vtx_audio_dev *drv_data,
	int stream, struct vtx_pcm_dma_params *dma_data)
{
	struct device *dev = drv_data->dev;
	int ret;

	DMADBG("+++");
	/*
	 * Driver data update
	 */
	if (stream == SNDRV_PCM_STREAM_PLAYBACK) {
		drv_data->txchan = dma_request_chan(dev, "tx");
		if (IS_ERR(drv_data->txchan)) {
			ret = PTR_ERR(drv_data->txchan);
			drv_data->txchan = NULL;
			return ret;
		}
	} else if (stream == SNDRV_PCM_STREAM_CAPTURE) {
		drv_data->rxchan = dma_request_chan(dev, "rx");
		if (IS_ERR(drv_data->rxchan)) {
			ret = PTR_ERR(drv_data->rxchan);
			drv_data->rxchan = NULL;
			return ret;
		}
	} else {
		return 0;
	}
	/*
	 * pass info from device tree
	 */
	if (stream == SNDRV_PCM_STREAM_PLAYBACK) {
		/* Tx */
		dma_data->channel   = drv_data->txchan;
		dma_data->burst_len = drv_data->txburst;
		dma_data->sg_burst  = drv_data->dma_sg_burst;
	} else if (stream == SNDRV_PCM_STREAM_CAPTURE) {
		/* Rx */
		dma_data->channel   = drv_data->rxchan;
		dma_data->burst_len = drv_data->rxburst;
		dma_data->sg_burst  = drv_data->dma_sg_burst;
		dma_data->reg_base_addr = drv_data->pdma_base;
	} else
		;

	util_dump_mmr("PDMA", dma_data->reg_base_addr, 12);
	DMADBG("---");
	return 0;

}

static void _dma_exit(struct vtx_audio_dev *drv_data, int stream)
{
	struct dma_chan *ch;

	if (stream == SNDRV_PCM_STREAM_PLAYBACK) {
		/* Tx */
		ch = drv_data->txchan;
		if (ch) {
			dmaengine_terminate_sync(ch);
			dma_release_channel(ch);
			drv_data->txchan = NULL;
		}
	} else if (stream == SNDRV_PCM_STREAM_CAPTURE) {
		/* Rx */
		ch = drv_data->rxchan;
		if (ch) {
			dmaengine_terminate_sync(ch);
			dma_release_channel(ch);
			drv_data->rxchan = NULL;
		}
	} else
		;

}

#else

static void __dma_maxburst_init(struct vtx_audio_dev *drv_data)
{
	struct dma_slave_caps caps;
	u32 max_burst, def_burst;
	int ret;

	def_burst = DMA_I2S_FIFO_LENGTH /*drvdata->fifo_len*/ / 2;

	/* Rx burst */
	ret = dma_get_slave_caps(drv_data->rxchan, &caps);
	if (!ret && caps.max_burst)
		max_burst = caps.max_burst;
	else
		max_burst = DMA_I2S_RX_BURST_LEVEL;

	drv_data->rxburst = min(max_burst, def_burst);

	/* Tx burst */
	ret = dma_get_slave_caps(drv_data->txchan, &caps);
	if (!ret && caps.max_burst)
		max_burst = caps.max_burst;
	else
		max_burst = DMA_I2S_TX_BURST_LEVEL;

	drv_data->txburst = min(max_burst, def_burst);

	DMADBG("burst Rx %u, Tx %u\n", drv_data->rxburst, drv_data->txburst);
}

static void __dma_sg_burst_init(struct vtx_audio_dev *drv_data)
{
	struct dma_slave_caps tx = { 0 }, rx = { 0 };

	dma_get_slave_caps(drv_data->txchan, &tx);
	dma_get_slave_caps(drv_data->rxchan, &rx);

	DMADBG(">>> max SG burst tx %d, rx %d\n", tx.max_sg_burst, rx.max_sg_burst);
	if (tx.max_sg_burst > 0 && rx.max_sg_burst > 0)
		drv_data->dma_sg_burst = min(tx.max_sg_burst, rx.max_sg_burst);
	else if (tx.max_sg_burst > 0)
		drv_data->dma_sg_burst = tx.max_sg_burst;
	else if (rx.max_sg_burst > 0)
		drv_data->dma_sg_burst = rx.max_sg_burst;
	else
		drv_data->dma_sg_burst = 0;

	DMADBG("SG burst %d\n", drv_data->dma_sg_burst);
}

static int _dma_common_init(struct vtx_audio_dev *drv_data)
{
	struct device *dev = drv_data->dev;
	int ret;

	DMADBG("+++");
	drv_data->rxchan = dma_request_chan(dev, "rx");
	if (IS_ERR(drv_data->rxchan)) {
		ret = PTR_ERR(drv_data->rxchan);
		drv_data->rxchan = NULL;
		goto err_exit;
	}

	drv_data->txchan = dma_request_chan(dev, "tx");
	if (IS_ERR(drv_data->txchan)) {
		ret = PTR_ERR(drv_data->txchan);
		drv_data->txchan = NULL;
		goto free_rxchan;
	}

	__dma_maxburst_init(drv_data);
	__dma_sg_burst_init(drv_data);

	DMADBG("---");
	return 0;

free_rxchan:
	dma_release_channel(drv_data->rxchan);
	drv_data->rxchan = NULL;
err_exit:
	return ret;

}

static void _dma_common_exit(struct vtx_audio_dev *drv_data)
{
	struct dma_chan *ch;

	ch = drv_data->txchan;
	if (ch) {
		dmaengine_terminate_sync(ch);
		dma_release_channel(ch);
		drv_data->txchan = NULL;
	}

	ch = drv_data->rxchan;
	if (ch) {
		dmaengine_terminate_sync(ch);
		dma_release_channel(ch);
		drv_data->rxchan = NULL;
	}

}

static inline void _dma_rx_init(struct vtx_audio_dev *drv_data,
	struct vtx_pcm_dma_params *dma_data)
{
	dma_data->channel   = drv_data->rxchan;
	dma_data->burst_len = drv_data->rxburst;
	dma_data->sg_burst  = drv_data->dma_sg_burst;
}

static inline void _dma_tx_init(struct vtx_audio_dev *drv_data,
	struct vtx_pcm_dma_params *dma_data)
{
	dma_data->channel   = drv_data->txchan;
	dma_data->burst_len = drv_data->txburst;
	dma_data->sg_burst  = drv_data->dma_sg_burst;
}

#endif // #ifdef OPT_DMA_WORKAROUND

/* -------------------------------------------------------------------------- */

#if OPT_DMA_DESC_RECYCLE
static int _dma_cyclic(struct snd_pcm_substream *substream,
	struct dma_chan *dma_ch, u32 dma_num, size_t dma_size)
{
	struct dma_async_tx_descriptor *desc;
	struct snd_pcm_runtime *runtime = substream->runtime;
	bool is_play = (substream->stream == SNDRV_PCM_STREAM_PLAYBACK);
	/* DMA info */
	dma_cookie_t cookie;
	unsigned long flags = DMA_CTRL_ACK;

	/* Prepare and submit Front-End DMA channel */
	if (!substream->runtime->no_period_wakeup)
		flags |= DMA_PREP_INTERRUPT; // check...

	desc = dmaengine_prep_dma_cyclic(dma_ch,
		runtime->dma_addr,
		snd_pcm_lib_buffer_bytes(substream),
		snd_pcm_lib_period_bytes(substream),
		is_play ? DMA_MEM_TO_DEV : DMA_DEV_TO_MEM,
		flags);

	if (!desc) {
		ERR("dmaengine_prep_slave_sg() failed!\n");
		return -EIO;
	}

	desc->callback = is_play ? _dma_tx_done : _dma_rx_done;
	desc->callback_param = substream;

	cookie = dmaengine_submit(desc);
	if (cookie < 0) {
		ERR("dmaengine_submit() failed1\n");
		return -EIO;
	}

	dma_async_issue_pending(dma_ch);
	return 0;
}
#endif

/* -------------------------------------------------------------------------- */
#ifdef tag_DMA_RX
#endif

static int _dma_config_rx(struct snd_pcm_substream *substream)
{
	struct vtx_runtime_data *rt_data = substream->runtime->private_data;
	struct vtx_pcm_dma_params *dma_data = rt_data->dma_data;
	struct dma_slave_config rxconf;
	unsigned int burstlen, data_unit;

	DMADBG("\n");
	if (rt_data->dma_width == DMA_SLAVE_BUSWIDTH_2_BYTES)
		data_unit = 16;
	else if (rt_data->dma_width == DMA_SLAVE_BUSWIDTH_4_BYTES)
		data_unit = 32;
	else
		data_unit = 16;

	/* FIFO size: 64 bytes = 32-bit Word Size * 16 number */
	burstlen  = 2 * (32 / data_unit);

	memset(&rxconf, 0, sizeof(rxconf));
	rxconf.direction = DMA_DEV_TO_MEM;
	rxconf.src_addr = VPL_I2SSC_RX_MMR_BASE + I2S_RXDMA;
	rxconf.src_maxburst = burstlen;
	rxconf.src_addr_width = rt_data->dma_width; // from I2S bus
	rxconf.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
	rxconf.device_fc = false; // Flow Control

	return dmaengine_slave_config(dma_data->channel, &rxconf);
}

#if (OPT_DMA_DESC_RECYCLE == 0)
static int _dma_submit_rx(struct snd_pcm_substream *substream,
	struct scatterlist *sgl, unsigned int nents)
{
	struct vtx_runtime_data *rt_data = substream->runtime->private_data;
	struct vtx_pcm_dma_params *dma_data = rt_data->dma_data;
	struct dma_async_tx_descriptor *rxdesc; // _tx_: Transfer
	dma_cookie_t cookie;
	int ret;
#ifdef OPT_DEBUG_LOCAL
	struct pdma_chan *pdma_ch = to_pdma_chan(dma_data->channel);
#endif

	DMADBG("+++ Rx: id %d; desc cnt %d, head %d, tail %d\n",
		pdma_ch->chan_id,
		pdma_ch->pdma_descs_count, pdma_ch->head_idx, pdma_ch->tail_idx);

	rxdesc = dmaengine_prep_slave_sg(dma_data->channel, sgl, nents,
					 DMA_DEV_TO_MEM,
					 DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
	if (!rxdesc)
		return -ENOMEM;

	/* section complete callback */
	rxdesc->callback = _dma_rx_done;
	rxdesc->callback_param = substream;

	cookie = dmaengine_submit(rxdesc);
	ret = dma_submit_error(cookie);
	if (ret) {
		dmaengine_terminate_sync(dma_data->channel);
		return ret;
	}

	DMADBG("---\n");
	return 0;
}

static int _dma_desc_fill_rx(struct snd_pcm_substream *substream,
	struct dma_chan *dma_ch, u32 dma_num, size_t dma_size)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct scatterlist sg_tmp;
	dma_addr_t dma_addr, dma_addr_start;
	unsigned int index, offset;
	int ret;

	dma_addr_start = (uint32_t)runtime->dma_addr;

	/* fill DMA desc. */
	for (index = 0; index < dma_num; index++) {
		DMADBG("Rx SG[%d] +++\n", index);
		sg_init_table(&sg_tmp, 1);

		offset = dma_size * index;
		dma_addr = (uint32_t)dma_addr_start + offset;

		sg_dma_len(&sg_tmp) = dma_size; // fill Length
		sg_dma_address(&sg_tmp) = dma_addr; // fill Address

		ret = _dma_submit_rx(substream, &sg_tmp, 1);
		if (ret) {
			ERR("DMA submit Rx[%d] failed!\n", index);
			return ret;
		}
		util_dump_mmr("  CH.I2S RX", get_dma_ch_base(dma_ch), 11);

		/* trigger DMA engine -> wait for I2S module request */
		dma_async_issue_pending(dma_ch);

		DMADBG("Rx SG[%d] ---\n", index);
	}

	return 0;
}
#endif

/* section complete callback */
static void _dma_rx_done(void *arg)
{
	struct snd_pcm_substream *substream = arg;
	struct vtx_runtime_data *rt_data = substream->runtime->private_data;
#if (OPT_DMA_DESC_RECYCLE == 0)
	struct vtx_pcm_dma_params *dma_data = rt_data->dma_data;
	struct dma_chan *dma_ch = dma_data->channel;
#endif
	unsigned int desc_num = rt_data->dma_period_num;
	size_t dma_size = rt_data->dma_period_size;

	rt_data->int_cnt++; // start from 1

	/* update DMA descriptor if necessary */
#if OPT_DMA_DESC_RECYCLE
	/* handled by DMA framework */
#else
	if ((rt_data->int_cnt % desc_num) == (desc_num / 2))
		_dma_desc_fill_rx(substream, dma_ch, desc_num, dma_size);
#endif

	/* update DMA transferred Position */
	rt_data->dma_period_pos += dma_size;
	if ((rt_data->int_cnt % desc_num) == 0) {
		DMADBG("DMA period number %d, size %zd -> reset pos %d\n",
			desc_num, dma_size, rt_data->dma_period_pos);
		rt_data->dma_period_pos = 0; // wrap around
	}

	if (rt_data->active)
		snd_pcm_period_elapsed(substream);
	else
		WRN("Streaming is not active!");

	DMADBG("SEC_CMPT callback; RT data: active %d, cnt %d, pos %d\n",
		rt_data->active, rt_data->int_cnt, rt_data->dma_period_pos);
}

/* -------------------------------------------------------------------------- */
#ifdef tag_DMA_TX
#endif

static int _dma_config_tx(struct snd_pcm_substream *substream)
{
	struct vtx_runtime_data *rt_data = substream->runtime->private_data;
	struct vtx_pcm_dma_params *dma_data = rt_data->dma_data;
	struct dma_slave_config txconf;
	unsigned int burstlen, data_unit;

	DMADBG("\n");
	if (rt_data->dma_width == DMA_SLAVE_BUSWIDTH_2_BYTES)
		data_unit = 16;
	else if (rt_data->dma_width == DMA_SLAVE_BUSWIDTH_4_BYTES)
		data_unit = 32;
	else
		data_unit = 16;

	/* S16_LE: 32-bit to 2 x 16-bit, x2: Left & Right channel data */
	burstlen  = 2 * (32 / data_unit);

	memset(&txconf, 0, sizeof(txconf));
	txconf.direction = DMA_MEM_TO_DEV;
	txconf.dst_addr = VPL_I2SSC_TX_MMR_BASE + I2S_TXDMA;
	txconf.dst_maxburst = burstlen;
	txconf.dst_addr_width = rt_data->dma_width; // to I2S bus
	txconf.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
	txconf.device_fc = false; // Flow Control

	return dmaengine_slave_config(dma_data->channel, &txconf);
}

#if (OPT_DMA_DESC_RECYCLE == 0)
/*
 * nents: Number of Entry
 */
static int _dma_submit_tx(struct snd_pcm_substream *substream,
	struct scatterlist *sgl, unsigned int nents)
{
	struct vtx_runtime_data *rt_data = substream->runtime->private_data;
	struct vtx_pcm_dma_params *dma_data = rt_data->dma_data;
	struct dma_async_tx_descriptor *txdesc; // _tx_: Transfer
	dma_cookie_t cookie;
	int ret;

	DMADBG("+++\n");
	txdesc = dmaengine_prep_slave_sg(dma_data->channel, sgl, nents,
				 DMA_MEM_TO_DEV,
				 DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
	if (!txdesc)
		return -ENOMEM;

	/* section complete callback */
	txdesc->callback = _dma_tx_done;
	txdesc->callback_param = substream;

	cookie = dmaengine_submit(txdesc);
	ret = dma_submit_error(cookie);
	if (ret) {
		dmaengine_terminate_sync(dma_data->channel);
		return ret;
	}

	DMADBG("---\n");
	return 0;
}

static int _dma_desc_fill_tx(struct snd_pcm_substream *substream,
	struct dma_chan *dma_ch, u32 dma_num, size_t dma_size)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct scatterlist sg_tmp;
	dma_addr_t dma_addr, dma_addr_start;
	unsigned int index, offset;
	int ret;
#if OPT_DMA_DESC_FILL_PROFILE
	ktime_t kt_b, kt_e;
	s64 duration;

	kt_b = ktime_get();
#endif

	dma_addr_start = (uint32_t)runtime->dma_addr;

	/* fill DMA desc. */
	for (index = 0; index < dma_num; index++) {
		DMADBG("Tx SG[%d] +++\n", index);
		sg_init_table(&sg_tmp, 1);

		offset = dma_size * index;
		dma_addr = (uint32_t)dma_addr_start + offset;

		sg_dma_len(&sg_tmp) = dma_size; // fill Length
		sg_dma_address(&sg_tmp) = dma_addr; // fill Address

		ret = _dma_submit_tx(substream, &sg_tmp, 1);
		if (ret) {
			ERR("DMA submit Tx[%d] failed!\n", index);
			return ret;
		}
		util_dump_mmr("  CH.I2S TX", get_dma_ch_base(dma_ch), 11);

		/* trigger DMA engine -> wait for I2S module request */
		dma_async_issue_pending(dma_ch);

		DMADBG("Tx SG[%d] ---\n", index);
	}

#if OPT_DMA_DESC_FILL_PROFILE
	kt_e = ktime_get();
	duration = ktime_us_delta(kt_e, kt_b);
	MSG(">>> fill desc. in us: %llu", duration);
#endif
	return 0;
}
#endif

/* section complete callback */
static void _dma_tx_done(void *arg)
{
	struct snd_pcm_substream *substream = arg;
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct vtx_runtime_data *rt_data = runtime->private_data;
#if (OPT_DMA_DESC_RECYCLE == 0)
	struct vtx_pcm_dma_params *dma_data = rt_data->dma_data;
	struct dma_chan *dma_ch = dma_data->channel;
#endif
	unsigned int desc_num = rt_data->dma_period_num;
	size_t dma_size = rt_data->dma_period_size;

	rt_data->int_cnt++; // start from 1

	/* update DMA descriptor if necessary */
#if OPT_DMA_DESC_RECYCLE
	/* handled by DMA framework */
#else
	if ((rt_data->int_cnt % desc_num) == (desc_num / 2))
		_dma_desc_fill_tx(substream, dma_ch, desc_num, dma_size);
#endif

	/* update DMA transferred Position */
	rt_data->dma_period_pos += dma_size;
	if ((rt_data->int_cnt % desc_num) == 0) {
		DMADBG("DMA period number %d, size %zd -> reset pos %d\n",
			desc_num, dma_size, rt_data->dma_period_pos);
		rt_data->dma_period_pos = 0; // wrap around
	}

	if (rt_data->active)
		snd_pcm_period_elapsed(substream);
	else
		WRN("Streaming is not active!");

	DMADBG("SEC_CMPT callback; RT data: active %d, cnt %d, pos %d\n",
		rt_data->active, rt_data->int_cnt, rt_data->dma_period_pos);
}

/* ---------------------------------------------------------------------------*/
#ifdef tag_Operations
#endif

static int _pcm_start_dma(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct vtx_runtime_data *rt_data = runtime->private_data;
	/* DMA info */
	struct vtx_pcm_dma_params *dma_data = rt_data->dma_data;
	struct dma_chan *dma_ch;
	unsigned int dma_size, dma_num;
	int ret;

	DBG("+++\n");

	dma_num = runtime->periods;
	// transfer one period size data for each DMA move
	dma_size = snd_pcm_lib_period_bytes(substream);
	DBG("DMA period num %d, size: %u, width: %d\n",
		dma_num, dma_size,
		(rt_data->dma_width == DMA_SLAVE_BUSWIDTH_2_BYTES) ? 16 : 32);

	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
		/* Playback */
		dma_ch = dma_data->channel;

		_dma_config_tx(substream);
#if OPT_DMA_DESC_RECYCLE
		ret = _dma_cyclic(substream, dma_ch, dma_num, dma_size);
#else
		ret = _dma_desc_fill_tx(substream,
			dma_ch, dma_num, dma_size);
#endif
		rt_data->dma_period_pos = 0;
		rt_data->dma_period_num = dma_num;
		rt_data->dma_period_size = dma_size;
		rt_data->int_cnt = 0;
	} else {
		/* Capture */
		dma_ch = dma_data->channel;

		_dma_config_rx(substream);
#if OPT_DMA_DESC_RECYCLE
		ret = _dma_cyclic(substream, dma_ch, dma_num, dma_size);
#else
		ret = _dma_desc_fill_rx(substream,
			dma_ch, dma_num, dma_size);
#endif
		rt_data->dma_period_pos = 0;
		rt_data->dma_period_num = dma_num;
		rt_data->dma_period_size = dma_size;
		rt_data->int_cnt = 0;
	}

	if (ret < 0) {
		ERR("fill DMA desc. failed!\n");
		return ret;
	}
	DBG("---\n");
	return 0;
}

static void _pcm_stop_dma(struct snd_pcm_substream *substream)
{
	DBG("\n");
}

/* ---------------------------------------------------------------------------*/
#ifdef tag_Callback_Function
#endif

static int vtx_pcm_trigger(struct snd_soc_component *component,
	struct snd_pcm_substream *substream, int cmd)
{
	struct vtx_runtime_data *rt_data = substream->runtime->private_data;
	int ret = 0;

	DBG("+++ CMD %d\n", cmd);
	spin_lock(&rt_data->lock);
	switch (cmd) {
	case SNDRV_PCM_TRIGGER_START:
		rt_data->active = 1;
		ret = _pcm_start_dma(substream);
		break;
	case SNDRV_PCM_TRIGGER_STOP:
		rt_data->active = 0;
		_pcm_stop_dma(substream);
		break;
	default:
		ret = -EINVAL;
		break;
	}
	spin_unlock(&rt_data->lock);
	DBG("--- ret %d\n", ret);

	return ret;
}

static int vtx_pcm_prepare(struct snd_soc_component *component,
	struct snd_pcm_substream *substream)
{
	DBG("\n");
	return 0;
}

/*
 * DMA ring buffer managered by ALSA framework
 *   - report hardware pointer (frames, typedef "unsigned long")
 *   - given in H/W physical address
 */
static snd_pcm_uframes_t vtx_pcm_pointer(struct snd_soc_component *component,
	struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct vtx_runtime_data *rt_data = runtime->private_data;

	return bytes_to_frames(substream->runtime, rt_data->dma_period_pos);
}

#ifdef OPT_TDM_4
static int vtx_pcm_4ch_copy(struct snd_soc_component *component,
	struct snd_pcm_substream *ss, int channel,
	snd_pcm_uframes_t src, void __user *dst,
	snd_pcm_uframes_t count)
{
	struct snd_pcm_runtime *runtime = ss->runtime;
	int dma_buf_index, user_buf_index;
	int totalchannelnum = runtime->channels;
	int byte_num_of_sample = 2;
	int ret = 0;
	char *hwbuf = runtime->dma_area + frames_to_bytes(runtime, src);

	user_buf_index = 0;
	dma_buf_index = channel * byte_num_of_sample;

	while (count > 0) {
		ret = copy_to_user(dst + user_buf_index, hwbuf + dma_buf_index,
				byte_num_of_sample);
		if (ret)
			return -EFAULT;

		user_buf_index += byte_num_of_sample;
		dma_buf_index += totalchannelnum * byte_num_of_sample;
		count--;
	}

	return 0;
}
#endif

static int vtx_pcm_open(struct snd_soc_component *component,
	struct snd_pcm_substream *substream)
{
	struct vtx_audio_dev *drv_data =
		snd_soc_component_get_drvdata(component);
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct vtx_runtime_data *rt_data; // RunTime data
	struct vtx_pcm_dma_params *dma_data;
	int ret = 0;

	MSG("component %px, substream %px\n", component, substream);
	DDBG(drv_data->dev, "substream [%s] stream(dir) %d, pcm %px\n",
		substream->name, substream->stream, substream->pcm);
	snd_soc_set_runtime_hwparams(substream, &vtx_pcm_hardware);

	rt_data = kzalloc(sizeof(*rt_data), GFP_KERNEL);
	if (rt_data == NULL)
		return -ENOMEM;

	dma_data = kzalloc(sizeof(*dma_data), GFP_KERNEL);
	if (dma_data == NULL) {
		kfree(rt_data);
		return -ENOMEM;
	}

#ifdef OPT_DMA_WORKAROUND
	ret = _dma_init(drv_data, substream->stream, dma_data);
	if (ret) {
		ERR("DMA %s initial failed!\n", (substream->stream) ? "Rx" : "Tx");
		kfree(dma_data);
		kfree(rt_data);
		return ret;
	}
#else
	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
		_dma_tx_init(drv_data, dma_data);
	else if (substream->stream == SNDRV_PCM_STREAM_CAPTURE)
		_dma_rx_init(drv_data, dma_data);
	else
		;
#endif

	spin_lock_init(&rt_data->lock);
	rt_data->dma_data = dma_data;
	rt_data->active = 0;

	/* link private data */
	runtime->private_data = rt_data;

	return ret;
}

static int vtx_pcm_close(struct snd_soc_component *component,
	struct snd_pcm_substream *substream)
{
#ifdef OPT_DMA_WORKAROUND
	struct vtx_audio_dev *drv_data =
		snd_soc_component_get_drvdata(component);
#endif
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct vtx_runtime_data *rt_data = runtime->private_data;
	struct vtx_pcm_dma_params *dma_data = rt_data->dma_data;

	MSG("\n");
#ifdef OPT_DMA_WORKAROUND
	_dma_exit(drv_data, substream->stream);
#endif

	kfree(dma_data);
	kfree(rt_data);
	return 0;
}

static int vtx_pcm_hw_params(struct snd_soc_component *component,
	struct snd_pcm_substream *substream, struct snd_pcm_hw_params *hw_params)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct vtx_runtime_data *rt_data = runtime->private_data;
	snd_pcm_format_t format = params_format(hw_params);
	unsigned int ch_num = params_channels(hw_params);

	MSG("\n");

	switch (format) {
	case SNDRV_PCM_FORMAT_S16_LE:
		if (ch_num == 2)
			rt_data->dma_width = DMA_SLAVE_BUSWIDTH_2_BYTES;
		else
			rt_data->dma_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
		break;
	case SNDRV_PCM_FORMAT_S32_LE:
		rt_data->dma_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
		break;
	default:
		rt_data->dma_width = DMA_SLAVE_BUSWIDTH_UNDEFINED;
		break;
	}

	return snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params));
}

static int vtx_pcm_hw_free(struct snd_soc_component *component,
	struct snd_pcm_substream *substream)
{
	MSG("\n");
	return snd_pcm_lib_free_pages(substream);
}

static void vtx_pcm_destruct(struct snd_soc_component *component,
	struct snd_pcm *pcm)
{
#ifndef OPT_DMA_WORKAROUND
	struct vtx_audio_dev *drv_data =
		snd_soc_component_get_drvdata(component);
#endif

	DBG("+++\n");
	_dma_buffer_free(pcm);
#ifndef OPT_DMA_WORKAROUND
	_dma_common_exit(drv_data);
#endif
	DBG("---\n");
}

static int vtx_pcm_construct(struct snd_soc_component *component,
	struct snd_soc_pcm_runtime *rtd)
{
#ifndef OPT_DMA_WORKAROUND
	struct vtx_audio_dev *drv_data =
		snd_soc_component_get_drvdata(component);
#endif
	struct snd_card *card = rtd->card->snd_card;
	struct snd_pcm *pcm = rtd->pcm;
	int ret;

	DBG("+++\n");

	/* ? */
	if (!card->dev->dma_mask)
		card->dev->dma_mask = &vtx_pcm_dma_mask;
	if (!card->dev->coherent_dma_mask)
		card->dev->coherent_dma_mask = 0xffffffff;

#ifndef OPT_DMA_WORKAROUND
	ret = _dma_common_init(drv_data);
	if (ret)
		return ret;
#endif

	if (pcm->streams[SNDRV_PCM_STREAM_PLAYBACK].substream) {
		ret = _dma_buffer_init(pcm, SNDRV_PCM_STREAM_PLAYBACK);
		if (ret) {
			ERR("allocate DMA buffer for Playback stream failed!\n");
			return ret;
		}
	}

	if (pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream) {
		ret = _dma_buffer_init(pcm, SNDRV_PCM_STREAM_CAPTURE);
		if (ret) {
			ERR("allocate DMA buffer for Capture stream failed!\n");
			return ret;
		}
	}

	return 0;
}

static const struct snd_soc_component_driver vtx_pcm_comp_driver = {
	.name  = PCM_DRV_NAME,
	.legacy_dai_naming = 1,
	/* basic operation */
	.open  = vtx_pcm_open,
	.close = vtx_pcm_close,
//	.ioctl = snd_pcm_lib_ioctl, // snd_soc_pcm_component_ioctl
	/* H/W */
	.hw_params = vtx_pcm_hw_params,
	.hw_free   = vtx_pcm_hw_free,
	/* data operation */
	.prepare = vtx_pcm_prepare,
	.trigger = vtx_pcm_trigger,
	.pointer = vtx_pcm_pointer,
#ifdef OPT_TDM_4
	.copy = vtx_pcm_4ch_copy,
#endif
	/* pcm creation and destruction */
	.pcm_construct  = vtx_pcm_construct,
	.pcm_destruct   = vtx_pcm_destruct,
};

/* ---------------------------------------------------------------------------*/
#ifdef tag_platform_driver
#endif

#define PDMAC_MMR_BASE  0xC5000000

/* current triggered by I2S driver */
int vtx_soc_platform_register(struct device *dev)
{
	struct vtx_audio_dev *vtx_dev;
	unsigned int hw_version;
	int ret;

	MSG("\n");

	vtx_dev = (struct vtx_audio_dev *)dev_get_drvdata(dev);
	if (IS_ERR(vtx_dev))
		return PTR_ERR(vtx_dev);
	MSG("I2S virtual IRQ number: Rx %u, Tx %u\n",
		vtx_dev->virq_rx_num, vtx_dev->virq_tx_num);

	/* PDMA */
	request_mem_region(PDMAC_MMR_BASE, 0x100, "PDMA");
	vtx_dev->pdma_base = ioremap(PDMAC_MMR_BASE, 0x400);
	if (IS_ERR(vtx_dev->pdma_base)) {
		ERR("get PDMA ioremap resource failed!\n");
		return PTR_ERR(vtx_dev->pdma_base);
	}

	hw_version = readl(vtx_dev->pdma_base);
	if (hw_version) {
#define DRV  "Install VPL_PCM device driver version "
#define HW   " on hardware version "
		dev_info(dev, DRV "%d.%d.%d.%d" HW "%d.%d.%d.%d complete !!\n",
			(int)((VPL_PCM_VERSION >>  0) & 0xFF),
			(int)((VPL_PCM_VERSION >>  8) & 0xFF),
			(int)((VPL_PCM_VERSION >> 16) & 0xFF),
			(int)((VPL_PCM_VERSION >> 24) & 0xFF),
			(int)(hw_version >> 24) & 0xFF,
			(int)(hw_version >> 16) & 0xFF,
			(int)(hw_version >>  8) & 0xFF,
			(int)(hw_version >>  0) & 0xFF);
	} else {
		ERR("get PCM H/W version failed!\n");
		return -EFAULT;
	}

	/* SoC Component */
	ret = devm_snd_soc_register_component(dev, &vtx_pcm_comp_driver,
			NULL, 0);
	if (ret)
		return -EFAULT;

	return 0;
}

void vtx_soc_platform_unregister(struct device *dev)
{
	MSG("\n");

	/* SoC Component */
	snd_soc_unregister_component(dev);
}

/* ---------------------------------------------------------------------------*/
/* DT */
#if CFG_PLATFORM_DRIVER

#ifdef CONFIG_OF
static const struct of_device_id vtx_pcm_of_match[] = {
	{ .compatible = "vtx,audio-pcm-dma" },
	{ },
};
#endif

static int vtx_pcm_probe(struct platform_device *pdev)
{
	int ret = 0;
//	struct device *dev = &pdev->dev;
	struct resource *res;

	MSG("\n");
	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (res == NULL) {
		ERR("get resource failed!\n");
//		return -EFAULT;
	}

	return ret;
}

static int vtx_pcm_remove(struct platform_device *pdev)
{
	int ret = 0;

	MSG("\n");

	return ret;
}

static struct platform_driver vtx_pcm_driver = {
	.probe	= vtx_pcm_probe,
	.remove	= vtx_pcm_remove,
	.driver	= {
		.name	= PCM_DRV_NAME,
		.owner = THIS_MODULE,
#ifdef CONFIG_OF
		.of_match_table	= vtx_pcm_of_match,
#endif
	},
};
module_platform_driver(vtx_pcm_driver);


MODULE_DESCRIPTION("VTX PCM (DMA) Platform Driver");
MODULE_AUTHOR("Kneron Ltd.");
MODULE_LICENSE("GPL");
#endif // #if CFG_PLATFORM_DRIVER

