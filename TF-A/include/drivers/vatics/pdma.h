#ifndef PDMA_H
#define PDMA_H

#define PDMA_TXCH_INTR_NORMAL  (PDMA_TXCH_INTR_RCI_EN | \
				PDMA_TXCH_INTR_SCI_EN | \
				PDMA_TXCH_INTR_BEI_EN | \
				PDMA_TXCH_INTR_SGSCI_EN)

#define PDMA_RXCH_INTR_NORMAL  (PDMA_RXCH_INTR_FCI_EN | \
				PDMA_RXCH_INTR_RCI_EN | \
				PDMA_RXCH_INTR_SCI_EN | \
				PDMA_RXCH_INTR_BEI_EN)

#if defined(IMAGE_BL1)
// BL1 disable PDMA to resuce code size
#define PDMA_ENABLE 0
#else
#define PDMA_ENABLE 1
#endif

struct pdma_desc {
	uint32_t section_addr;
	uint32_t section_size;
};

enum pdma_channel_type {
	PDMA_RXCH = 0,
	PDMA_TXCH = 1,
};

enum pdma_channel_event {
	PDMA_CH_EVENT_UPDATE = 0,
	PDMA_CH_EVENT_FIRE = 1,
};

enum pdma_device_type {
	PDMA_DEVICE_SSIC0 = 0,
	PDMA_DEVICE_SSIC1 = 1,
	PDMA_DEVICE_SSIC2 = 2,
	PDMA_DEVICE_SSIC3 = 3,
	PDMA_DEVICE_I2SSC = 4,
	PDMA_DEVICE_UART0 = 5,
	PDMA_DEVICE_UART1 = 6,
	PDMA_DEVICE_UART2 = 7,
	PDMA_DEVICE_UART3 = 8,
	PDMA_DEVICE_UART4 = 9,
};

enum pdma_data_unit {
	PDMA_DATAUNIT_1B = 0,
	PDMA_DATAUNIT_2B,
	PDMA_DATAUNIT_RESERVE,
	PDMA_DATAUNIT_4B,
};

struct pdma_init {
	uint32_t paddr;
	uint32_t pdma_descs_count;
};

struct pdma_conf {
	enum pdma_data_unit data_unit;
	uint32_t intr_en;
	uint32_t burstlen;
	uint32_t sctrl;
	uint32_t flowctrl;
};

struct pdma_prep {
	uint32_t xfer_addr;
	uint32_t xfer_len;
	uint32_t sect_intr;
	uint32_t sg_intr;
	uint32_t data_swap;
};

struct pdma_chan {
	/* channel info */
	uint32_t base_addr;
	uint32_t chan_num;
	enum pdma_channel_type chan_type;
	enum pdma_device_type dev_type;

	/* ring info*/
	struct pdma_desc *pdma_descs;
	uint32_t paddr;
	uint32_t pdma_descs_count;
	uint32_t tail_idx;
	uint32_t wrap;

	/* parameters */
	enum pdma_data_unit data_unit;
	uint32_t intr_en;
	uint32_t burstlen;
	uint32_t sctrl;
	uint32_t flowctrl;

	uint32_t xfer_addr;
	uint32_t xfer_len;
	uint32_t sect_intr;
	uint32_t sg_intr;
	uint32_t data_swap;

	void (*init)(struct pdma_chan *, struct pdma_init *);
	void (*conf)(struct pdma_chan *, struct pdma_conf *);
	void (*prep)(struct pdma_chan *, struct pdma_prep *);
	void (*xfer)(struct pdma_chan *);
	void (*exit)(struct pdma_chan *);
};

uint32_t pdma_get_version(void);
void pdma_request_channel(struct pdma_chan *chan);


#endif
