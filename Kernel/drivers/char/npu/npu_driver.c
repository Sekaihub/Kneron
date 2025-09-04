// SPDX-License-Identifier: GPL-2.0-only
/*
 *
 * Copyright (C) 2022 VATICS Inc.
 *
 */
#include "npu_driver.h"

//#define SYSC_CHIP_VER 0x14
#define SYSC_RST2_SET 0x168
#define SYSC_RST2_CLR 0x16C

static unsigned int gsdwMajor = 193;


MODULE_AUTHOR("VATICS Inc.");
MODULE_LICENSE("GPL");
module_param(gsdwMajor, int, 0644);
MODULE_PARM_DESC(gsdwMajor, "Major number for NPU module");

static void __maybe_unused reset_npu(struct npu_shared_info *info)
{
	struct regmap *regmap = info->sysc_regmap;
	struct clk *clk = info->clk;

	clk_disable(clk);
	/*
	 * bit8: core reset
	 * bit7: axi reset
	 * bit6: apb reset
	 */
	regmap_write(regmap, SYSC_RST2_CLR, 0x1C0);
	regmap_write(regmap, SYSC_RST2_SET, 0x1C0);
	clk_enable(clk);
}

static void __maybe_unused dump_npu_info(struct npu_info *info)
{
	pr_info("index = %d\n", info->index);
	pr_info("phy work_addr = %p\n", info->work_addr);
	pr_info("virt work_addr = %p\n", info->work_virt_addr);
	pr_info("work size  = %d\n", info->work_size);
	pr_info("phy inst_addr = %p\n", info->inst_addr);
	pr_info("virt inst_addr = %p\n", info->inst_virt_addr);
	pr_info("inst size  = %d\n", info->inst_size);
	pr_info("phy wt_addr = %p\n", info->wt_addr);
	pr_info("virt wt_addr = %p\n", info->wt_virt_addr);
	pr_info("wt size  = %d\n", info->wt_size);
	pr_info("phy src_addr = %p\n", info->src_addr);
	pr_info("virt src_addr = %p\n", info->src_virt_addr);
	pr_info("src size  = %d\n", info->src_size);
	pr_info("phy dst_addr = %p\n", info->dst_addr);
	pr_info("virt dst_addr = %p\n", info->dst_virt_addr);
	pr_info("dst size  = %d\n", info->dst_size);
	pr_info("phy const input addr = %p\n", info->const_input_addr);
	pr_info("virt const input addr = %p\n", info->const_input_virt_addr);
	pr_info("const input  size  = %d\n", info->const_input_size);
}

static void __maybe_unused dump_cmdbuf_virt_addr(struct cmd_buf *cmd)
{
	pr_info("dump cmdbuf virt info\n");
	pr_info("inst_kvirt_addr = %p\n", cmd->inst_kvirt_addr);
	pr_info("wt_kvirt_addr = %p\n", cmd->wt_kvirt_addr);
	pr_info("src_kvirt_addr = %p\n", cmd->src_kvirt_addr);
	pr_info("dst_kvirt_addr = %p\n", cmd->dst_kvirt_addr);
}

static int npu_remap_buf(struct npu_info *info, struct cmd_buf *cmd)
{
	//dump_npu_info(info);
	cmd->inst_kvirt_addr = memremap((resource_size_t)info->inst_addr,
					info->inst_size, MEMREMAP_WB);
	if (!cmd->inst_kvirt_addr) {
		pr_err("inst remap failed\n");
		return -EINVAL;
	}

	cmd->wt_kvirt_addr = memremap((resource_size_t)info->wt_addr,
				      info->wt_size, MEMREMAP_WB);
	if (!cmd->wt_kvirt_addr) {
		pr_err("wt remap failed\n");
		return -EINVAL;
	}
	cmd->src_kvirt_addr = memremap((resource_size_t)info->src_addr,
				       info->src_size, MEMREMAP_WB);
	if (!cmd->inst_kvirt_addr) {
		pr_err("src remap failed\n");
		return -EINVAL;
	}
	cmd->dst_kvirt_addr = memremap((resource_size_t)info->dst_addr,
				       info->dst_size, MEMREMAP_WB);
	if (!cmd->inst_kvirt_addr) {
		pr_err("dst remap failed\n");
		return -EINVAL;
	}

	//dump_cmdbuf_virt_addr(cmd);

	return 0;
}

static void npu_unmap_buf(struct cmd_queue *cmdqueue)
{
	unsigned int i = 0;
	struct cmd_buf *cmd;

	for (i = 0; i < cmdqueue->cmdbuf_num; ++i) {
		cmd = cmdqueue->cmdbuf[i];

		memunmap(cmd->inst_kvirt_addr);
		memunmap(cmd->wt_kvirt_addr);
		memunmap(cmd->src_kvirt_addr);
		memunmap(cmd->dst_kvirt_addr);
	}
}

static void npu_free_cmdbuf(struct cmd_queue *cmdqueue)
{
	unsigned int i = 0;
	struct cmd_buf *cmd;

	for (i = 0; i < cmdqueue->cmdbuf_num; ++i) {
		cmd = cmdqueue->cmdbuf[i];
		kfree(cmd->npuinfo);
		kfree(cmd);
	}
}

static int cmd_done(struct npu_shared_info *npu_dev)
{
	struct cmd_buf *cmdbuf;
	unsigned long flags;
	struct npu_obj_info *obj_info;
	unsigned int ret = 0;

	spin_lock_irqsave(&(npu_dev->fh_lock), flags);
	obj_info = npu_dev->curr_obj;
	--obj_info->obj_cmdqueue.cmd_queued_count;
	spin_unlock_irqrestore(&(npu_dev->fh_lock), flags);

	spin_lock_irqsave(&obj_info->obj_cmdqueue.cmd_queue_lock, flags);
	cmdbuf = list_first_entry(&obj_info->obj_cmdqueue.cmd_queued_list,
				  struct cmd_buf, queued_entry);
	list_add_tail(&cmdbuf->done_entry,
		      &obj_info->obj_cmdqueue.cmd_done_list);
	list_del(&cmdbuf->queued_entry);
	spin_unlock_irqrestore(&obj_info->obj_cmdqueue.cmd_queue_lock, flags);

	return ret;
}

static int sel_the_next_cmd(struct npu_shared_info *npu_dev,
		struct npu_obj_info **cur_obj)
{
	struct npu_obj_info *obj_info, *next_obj_info = NULL;
	int ret = 0;
	unsigned int found = 0;

	obj_info = *cur_obj;
	next_obj_info = *cur_obj;

	if (list_is_singular(&npu_dev->fh_list)) {
		if (next_obj_info->obj_cmdqueue.cmd_queued_count)
			found = 1;
	} else {
		list_for_each_entry_continue(next_obj_info,
					     &npu_dev->fh_list, list) {
			if (next_obj_info->obj_cmdqueue.cmd_queued_count) {
				found = 1;
				break;
			}
		}

		if (!found) {
			next_obj_info = *cur_obj;
			list_for_each_entry_continue_reverse(next_obj_info,
							     &npu_dev->fh_list,
							     list) {
				if (next_obj_info->obj_cmdqueue.cmd_queued_count) {
					found = 1;
					break;
				}
			}
		}
	}

	if (found)
		*cur_obj = next_obj_info;
	else {
		next_obj_info = *cur_obj;
		if (!next_obj_info->obj_cmdqueue.cmd_queued_count)
			ret = -1;  //No more cmd need to process
	}
	return ret;
}

static irqreturn_t npu_isr(int irq, void *dev_id)
{
	struct npu_obj_info *obj_info = NULL;
	struct npu_obj_info *wakeup_obj_info = NULL;
	struct npu_shared_info *npu_dev = dev_id;
	struct cmd_buf *cmdbuf;
	unsigned long flags;

	spin_lock_irqsave(&npu_dev->isr_lock, flags);
	obj_info = npu_dev->curr_obj;
	wakeup_obj_info = npu_dev->curr_obj;
	npu_isrhead(npu_dev->hdevinfo);

	cmd_done(npu_dev);

	cmdbuf = list_last_entry(&obj_info->obj_cmdqueue.cmd_done_list,
				  struct cmd_buf, done_entry);

	cmdbuf->npuinfo->profile = npu_read_op_cycle(npu_dev->hdevinfo);

	sel_the_next_cmd(npu_dev, &obj_info);
	cmdbuf = list_first_entry(&obj_info->obj_cmdqueue.cmd_queued_list,
				  struct cmd_buf, queued_entry);

	if (!obj_info->obj_cmdqueue.cmd_queued_count) {
		npu_isrtail(npu_dev->hdevinfo, NULL);
		npu_dev->curr_obj = NULL;
	} else {
		if (npu_dev->auto_rst_en) {
			if (!npu_is_pause(npu_dev->hdevinfo)) {
				reset_npu(npu_dev);
				init_npu(npu_dev->hdevinfo);
			}
		}
		npu_isrtail(npu_dev->hdevinfo, cmdbuf);
		npu_dev->curr_obj = obj_info;
	}

	spin_unlock_irqrestore(&npu_dev->isr_lock, flags);
	wake_up(&wakeup_obj_info->obj_cmdqueue.cmd_done_wq);
	return IRQ_HANDLED;
}

static int npu_get_cur_freq(struct device *dev, unsigned long *freq)
{
	struct npu_shared_info *shared_info = dev_get_drvdata(dev);

	*freq = clk_get_rate(shared_info->clk);
	return 0;
}

static int npu_devfreq_target(struct device *dev, unsigned long *freq,
			      u32 flags)
{
	struct dev_pm_opp *opp;

	opp = devfreq_recommended_opp(dev, freq, flags);
	if (IS_ERR(opp))
		return PTR_ERR(opp);
	dev_pm_opp_put(opp);

	return dev_pm_opp_set_rate(dev, *freq);
}

static struct devfreq_dev_profile npu_devfreq_profile = {
	.target = npu_devfreq_target,
	.get_cur_freq = npu_get_cur_freq,
};

static int devfreq_init(struct npu_shared_info *shared_info)
{
	int ret;
	unsigned long cur_freq;
	struct devfreq *devfreq;
	struct npu_hw_devfreq *npu_devfreq = &shared_info->npu_devfreq;

	ret = devm_pm_opp_of_add_table(shared_info->dev);
	if (ret) {
		/* Optional, continue without devfreq */
		if (ret == -ENODEV)
			ret = 0;
		return ret;
	}

	cur_freq = clk_get_rate(shared_info->clk);

	npu_devfreq_profile.initial_freq = cur_freq;

	devfreq = devm_devfreq_add_device(shared_info->dev,
					  &npu_devfreq_profile,
					  DEVFREQ_GOV_USERSPACE,
					  NULL);
	if (IS_ERR(devfreq)) {
		dev_err(shared_info->dev, "Couldn't initialize NPU devfreq\n");
		return PTR_ERR(devfreq);
	}
	npu_devfreq->devfreq = devfreq;

	return 0;
}

static int start(struct npu_obj_info *objinfo, struct npu_info *npuinfo)
{
	unsigned int writeindex = 0;
	struct npu_shared_info *dev_info = objinfo->dev_info;
	unsigned long flags;
	unsigned long isr_flags;
	struct cmd_queue *cmdqueue = &objinfo->obj_cmdqueue;
	struct cmd_buf *cmdbuf;

	if (!cmdqueue->cmdbuf_num) {
		cmdbuf = kzalloc(sizeof(struct cmd_buf), GFP_KERNEL);
		cmdbuf->npuinfo = kzalloc(sizeof(struct npu_info), GFP_KERNEL);
	} else
		cmdbuf = cmdqueue->cmdbuf[npuinfo->index];
	memcpy(cmdbuf->npuinfo, npuinfo, sizeof(struct npu_info));

	npu_starthead(dev_info->hdevinfo);

	spin_lock_irqsave(&dev_info->isr_lock, isr_flags);
	spin_lock_irqsave(&(cmdqueue->cmd_queue_lock), flags);
	list_add_tail(&cmdbuf->queued_entry,
		      &objinfo->obj_cmdqueue.cmd_queued_list);
	++objinfo->obj_cmdqueue.cmd_queued_count;
	if (!npu_is_busy(dev_info->hdevinfo)) {
		dev_info->curr_obj = objinfo;
		if (dev_info->auto_rst_en) {
			if (!npu_is_pause(dev_info->hdevinfo)) {
				reset_npu(dev_info);
				init_npu(dev_info->hdevinfo);
			}
		}
	}

	npu_starttail(dev_info->hdevinfo,
		      writeindex, cmdbuf);
	spin_unlock_irqrestore(&(cmdqueue->cmd_queue_lock), flags);
	spin_unlock_irqrestore(&dev_info->isr_lock, isr_flags);

	return 0;
}

static int reset_queue(struct npu_obj_info *objinfo)
{
	struct npu_shared_info *dev_info = objinfo->dev_info;
	struct cmd_queue *cmdqueue = &objinfo->obj_cmdqueue;
	unsigned long flags;
	unsigned int ret = 0;
	struct cmd_buf *pos, *node;

	spin_lock_irqsave(&(dev_info->fh_lock), flags);

	/*remove done_list*/
	if (!list_empty(&cmdqueue->cmd_done_list)) {
		list_for_each_entry_safe(pos,
			node, &cmdqueue->cmd_done_list, done_entry)
			list_del(&pos->done_entry);
	}

	/*remove cmd_queued_list*/
	if (!list_empty(&cmdqueue->cmd_queued_list)) {
		list_for_each_entry_safe(pos, node,
			&cmdqueue->cmd_queued_list, queued_entry) {
			list_del(&pos->queued_entry);
			--objinfo->obj_cmdqueue.cmd_queued_count;
		}
	}
	spin_unlock_irqrestore(&(dev_info->fh_lock), flags);

	return ret;
}

static int waitcomplete(struct npu_obj_info *objinfo)
{
	int ret = 0;
	struct cmd_buf *cmdbuf;
	struct npu_shared_info *dev_info = objinfo->dev_info;
	unsigned long flags;

	if (dev_info->wait_timeout != 0) {
		ret = wait_event_timeout(objinfo->obj_cmdqueue.cmd_done_wq,
			!list_empty(&objinfo->obj_cmdqueue.cmd_done_list),
			dev_info->wait_timeout * HZ);

		if (ret != 0)  {
			/* remove done cmd*/
			spin_lock_irqsave(&dev_info->isr_lock, flags);
			cmdbuf = list_first_entry(
					&objinfo->obj_cmdqueue.cmd_done_list,
					  struct cmd_buf, done_entry);
			list_del(&cmdbuf->done_entry);
			spin_unlock_irqrestore(&dev_info->isr_lock, flags);
			if (!objinfo->obj_cmdqueue.cmdbuf_num) {
				kfree(cmdbuf->npuinfo);
				kfree(cmdbuf);
			}
		} else
			reset_queue(objinfo);
	} else {
		wait_event(objinfo->obj_cmdqueue.cmd_done_wq,
			   !list_empty(&objinfo->obj_cmdqueue.cmd_done_list));
		spin_lock_irqsave(&dev_info->isr_lock, flags);
		/* remove done cmd*/
		cmdbuf = list_first_entry(&objinfo->obj_cmdqueue.cmd_done_list,
					  struct cmd_buf, done_entry);
		list_del(&cmdbuf->done_entry);
		spin_unlock_irqrestore(&dev_info->isr_lock, flags);
		if (!objinfo->obj_cmdqueue.cmdbuf_num) {
			kfree(cmdbuf->npuinfo);
			kfree(cmdbuf);
		}
		ret = 1;
	}

	return ret;
}

static int close(struct inode *inode, struct file *file)
{
	struct npu_obj_info *objinfo = file->private_data;
	struct npu_shared_info *dev_info = objinfo->dev_info;
	struct cmd_queue *cmdqueue = &objinfo->obj_cmdqueue;

	file->private_data = NULL;

	mutex_lock(&dev_info->ioctl_lock);
	list_del_init(&objinfo->list);
	list_del_init(&objinfo->obj_cmdqueue.cmd_queued_list);
	list_del_init(&objinfo->obj_cmdqueue.cmd_done_list);
	dev_info->total_obj_num--;
	dev_info->open_count--;
	if (!cmdqueue->disable_remapping)
		npu_unmap_buf(cmdqueue);
	npu_free_cmdbuf(cmdqueue);
	mutex_unlock(&dev_info->ioctl_lock);
	kfree(objinfo);

	return 0;
}

static int open(struct inode *inode, struct file *file)
{
	struct npu_obj_info *objinfo;

	struct npu_shared_info *dev = container_of(inode->i_cdev,
						struct npu_shared_info, chrdev);

	if (file->private_data == NULL) {
		file->private_data = kmalloc(sizeof(struct npu_obj_info),
					     GFP_KERNEL);
		if (!file->private_data)
			return -ENOMEM;

		objinfo = (struct npu_obj_info *)file->private_data;

		objinfo->dev_info = dev;
		list_add_tail(&objinfo->list, &dev->fh_list);
		dev->total_obj_num++;
		objinfo->obj_cmdqueue.cmd_queued_count = 0;
		objinfo->obj_cmdqueue.cmdbuf_num = 0;
		objinfo->obj_cmdqueue.disable_remapping = 1;

		spin_lock_init(&(objinfo->obj_cmdqueue.cmd_queue_lock));
		INIT_LIST_HEAD(&objinfo->obj_cmdqueue.cmd_queued_list);
		INIT_LIST_HEAD(&objinfo->obj_cmdqueue.cmd_done_list);
		init_waitqueue_head(&objinfo->obj_cmdqueue.cmd_done_wq);
	} else {
		pr_info("Exit Open function !!\n");
		return -EBUSY;
	}

	mutex_lock(&dev->ioctl_lock);

	if (!dev->open_count)
		npu_open(dev->hdevinfo);

	dev->open_count++;
	mutex_unlock(&dev->ioctl_lock);

	return 0;
}

static long ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	struct npu_obj_info *objinfo = file->private_data;
	unsigned int dwVersionNum;
	int scError;
	struct npu_info npuinfo;
	struct cmd_buf cmdbuf;
	struct cmd_buf *tmp_cmdbuf;
	struct npu_shared_info *dev_info = objinfo->dev_info;
	struct cmd_queue *cmdqueue = &objinfo->obj_cmdqueue;
	unsigned int i = 0;
	unsigned int timeout = 0;
	unsigned int auto_rst_en = 0;
	struct npu_req_cmd_buf req_buf;

	if (file->private_data == NULL) {
		pr_err("Device does not exist !!\n");
		return -ENODEV;
	}

	if ((_IOC_TYPE(cmd) != NPU_IOC_MAGIC) ||
	     (_IOC_NR(cmd) > NPU_IOC_MAX_NUMBER)) {
		pr_err("Incorrect Ioctl command !!\n");
		return -ENOTTY;
	}

	if (_IOC_DIR(cmd) & _IOC_READ)
		scError = !access_ok((void *)arg, _IOC_SIZE(cmd));
	else if (_IOC_DIR(cmd) & _IOC_WRITE)
		scError = !access_ok((void *)arg, _IOC_SIZE(cmd));
	else
		scError = 0;

	if (scError != 0) {
		pr_err("Unsupport Ioctl command %d !!\n", cmd);
		return -EFAULT;
	}

	switch (cmd) {
	case NPU_IOC_START:
		scError = copy_from_user(&npuinfo, (unsigned int *)arg,
					sizeof(struct npu_info));
		cmdbuf.npuinfo = &npuinfo;
		mutex_lock(&dev_info->ioctl_lock);
		if (start(objinfo, &npuinfo) != 0) {
			pr_err("Exit Ioctl function !!\n");
			scError = -1;
		}
		mutex_unlock(&dev_info->ioctl_lock);
	break;
	case NPU_IOC_WAIT_COMPLETE:
		scError = copy_from_user(&npuinfo, (unsigned int *)arg,
						sizeof(struct npu_info));

		if (waitcomplete(objinfo) == 0) {
			pr_err("Wait complete timeout !!\n");
			scError = -ETIME;
			break;
		}
		if (!cmdqueue->cmdbuf_num)
			npuinfo.profile = npu_read_op_cycle(dev_info->hdevinfo);
		else {
			tmp_cmdbuf = cmdqueue->cmdbuf[npuinfo.index];
			npuinfo.profile = tmp_cmdbuf->npuinfo->profile;
		}
		scError = copy_to_user((unsigned int *)arg,
					&npuinfo, sizeof(struct npu_info));
		if (scError != 0) {
			pr_err("Exit Ioctl function !!\n");
			scError = -EFAULT;
		}
	break;
	case NPU_IOC_REQ_BUF:
		scError = copy_from_user(&req_buf, (unsigned int *)arg,
					sizeof(struct npu_req_cmd_buf));

		if (req_buf.buf_num > NPU_MAX_CMDBUF) {
			pr_err("buf_num isn't larger than %d !!\n",
				NPU_MAX_CMDBUF);
			scError = -EFAULT;
			break;
		}
		for (i = 0; i < req_buf.buf_num; ++i) {
			scError = copy_from_user(&npuinfo, req_buf.buf_info[i],
					sizeof(struct npu_info));
			cmdqueue->cmdbuf[i] = kmalloc(sizeof(struct cmd_buf),
						      GFP_KERNEL);
			tmp_cmdbuf = cmdqueue->cmdbuf[i];
			tmp_cmdbuf->npuinfo = kzalloc(sizeof(struct npu_info),
						     GFP_KERNEL);
			memcpy(tmp_cmdbuf->npuinfo, &npuinfo,
			       sizeof(struct npu_info));
			npuinfo.index = i;
			if (!cmdqueue->disable_remapping)
				npu_remap_buf(&npuinfo, cmdqueue->cmdbuf[i]);
			scError = copy_to_user(req_buf.buf_info[i],
					       &npuinfo,
					       sizeof(struct npu_info));
		}
		cmdqueue->cmdbuf_num = req_buf.buf_num;
	break;
	case NPU_IOC_GET_VERSION_NUMBER:
		dwVersionNum = NPU_VERSION;
		scError = copy_to_user((unsigned int *)arg,
					&dwVersionNum,
					sizeof(unsigned int));
		if (scError != 0) {
			pr_err("Exit Ioctl function !!\n");
			scError = -EFAULT;
		}
	break;
	case NPU_IOC_CONFIG_ADDR:
		scError = copy_from_user(&npuinfo, (unsigned int *)arg,
					sizeof(struct npu_info));
		config_npu_base(dev_info->hdevinfo,
				(uint32_t)(uint64_t)npuinfo.src_addr,
				(uint32_t)(uint64_t)npuinfo.dst_addr,
				(uint32_t)(uint64_t)npuinfo.work_addr,
				(uint32_t)(uint64_t)npuinfo.inst_addr,
				(uint32_t)(uint64_t)npuinfo.wt_addr,
				(uint32_t)(uint64_t)npuinfo.const_input_addr);
	break;
	case NPU_IOC_RESET_NPU:
		pr_debug("Reset NPU\n");
		reset_npu(dev_info);
		init_npu(dev_info->hdevinfo);
	break;
	case NPU_IOC_CONFIG_TIMEOUT:
		scError = copy_from_user(&timeout, (unsigned int *)arg,
					sizeof(unsigned int));
		if (npu_is_busy(dev_info->hdevinfo)) {
			scError = -EBUSY;
			pr_info("NPU is busy\n");
		} else
			dev_info->wait_timeout = timeout;
	break;
	case NPU_IOC_AUTO_RST_EN:
		scError = copy_from_user(&auto_rst_en, (unsigned int *)arg,
					sizeof(unsigned int));
		if (npu_is_busy(dev_info->hdevinfo)) {
			scError = -EBUSY;
			pr_info("NPU is busy\n");
		} else
			dev_info->auto_rst_en = auto_rst_en;
	break;
	default:
		pr_err("NO IOCTL Function !!\n");
		scError = -ENOTTY;
	}


	return scError;
}

static int mmap(struct file *file, struct vm_area_struct *vma)
{
	return 0;
}

static const struct file_operations npu_fops = {
	.owner = THIS_MODULE,
	.unlocked_ioctl = ioctl,
	.mmap = mmap,
	.open = open,
	.release = close,
};

static void cleanupModule(struct npu_shared_info *shared_info)
{
	if (shared_info != NULL) {
		if (shared_info->hdevinfo != NULL) {
			if (gsdwMajor != 0) {
				vma_unregister_device(MKDEV(gsdwMajor, 0));
				unregister_chrdev(gsdwMajor, "npu");
			}

			kfree(shared_info->hdevinfo);
		}

		kfree(shared_info);
	}
}

static int npu_probe(struct platform_device *pdev)
{
	int err;
	int ret;
	unsigned int dwDevInfoSize, dwVersionNum;
	struct resource *res;
	struct device *dev = &pdev->dev;
	phys_addr_t base_addr;
	int virq;
	dev_t dev_id;
	struct npu_shared_info *shared_info;

	void __iomem *reg_base;
	struct regmap *sysc_regmap;

	sysc_regmap = syscon_regmap_lookup_by_phandle(dev->of_node,
						      "sysc-regmap");


	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	base_addr = res->start;
	virq = platform_get_irq(pdev, 0);
	if (virq < 0) {
		pr_err("no irq resource specified\n");
		return virq;
	}
	reg_base = ioremap(base_addr,
			   resource_size(res));

	shared_info = devm_kzalloc(&pdev->dev, sizeof(struct npu_shared_info),
					GFP_KERNEL);
	if (!shared_info) {
		err = -ENOMEM;
		goto FAIL;
	}

	dwDevInfoSize = npu_getdevinfosize();

	shared_info->hdevinfo = kmalloc(dwDevInfoSize, GFP_KERNEL);
	if (!shared_info->hdevinfo) {
		err = -ENOMEM;
		goto FAIL;
	}
	memset(shared_info->hdevinfo, 0, dwDevInfoSize);

	shared_info->wait_timeout = 0;
	shared_info->auto_rst_en = 1;

	mutex_init(&shared_info->ioctl_lock);

	shared_info->irq = virq;
	shared_info->mmr_addr = base_addr;
	shared_info->dev = dev;
	shared_info->total_obj_num = 0;

	shared_info->sysc_regmap = sysc_regmap;

	shared_info->clk = devm_clk_get(dev, "kdpu_core");
	if (IS_ERR(shared_info->clk))
		return PTR_ERR(shared_info->clk);

	shared_info->axi_clk = devm_clk_get(dev, "kdpu_axi");
	if (IS_ERR(shared_info->clk))
		return PTR_ERR(shared_info->clk);

	shared_info->apb_clk = devm_clk_get(dev, "kdpu_apb");
	if (IS_ERR(shared_info->clk))
		return PTR_ERR(shared_info->clk);

	shared_info->pwr_clk = devm_clk_get(dev, "pwr_kdpu");
	if (IS_ERR(shared_info->clk))
		return PTR_ERR(shared_info->clk);

	ret = clk_prepare_enable(shared_info->clk);
	if (ret < 0)
		return ret;
	ret = clk_prepare_enable(shared_info->axi_clk);
	if (ret < 0)
		return ret;
	ret = clk_prepare_enable(shared_info->apb_clk);
	if (ret < 0)
		return ret;
	ret = clk_prepare_enable(shared_info->pwr_clk);
	if (ret < 0)
		return ret;

	ret = devfreq_init(shared_info);
	if (ret)
		return ret;

	reset_npu(shared_info);

	platform_set_drvdata(pdev, shared_info);

	request_mem_region(base_addr, resource_size(res), "NPU");

	ret = npu_setmmrinfo(shared_info->hdevinfo,
			     reg_base,
			     shared_info->clk,
			     NULL);
	if (ret) {
		err = -ENODEV;
		goto FAIL;
	}

	err = alloc_chrdev_region(&dev_id, 0, /* minor start */
				  1,
				  "npu");
	gsdwMajor = MAJOR(dev_id);
	cdev_init(&shared_info->chrdev, &npu_fops);
	err = cdev_add(&shared_info->chrdev, dev_id, 1);

	if (err < 0) {
		pr_err("Cannot get major number %d !!\n", (int)gsdwMajor);
		goto FAIL;
	}

	if (gsdwMajor == 0)
		gsdwMajor = err;

	vma_register_device(MKDEV(gsdwMajor, 0), NULL, "npu");

	dwVersionNum = npu_getversion(shared_info->hdevinfo);

	INIT_LIST_HEAD(&shared_info->fh_list);
	spin_lock_init(&shared_info->fh_lock);

	spin_lock_init(&shared_info->isr_lock);

	err = request_irq(shared_info->irq,
			  &npu_isr,
			  IRQF_TRIGGER_HIGH,
			  "npu",
			  shared_info);

	init_npu(shared_info->hdevinfo);

	return 0;

FAIL:
	cleanupModule(shared_info);
	pr_info("Exit InitialModule function !!\n");

	return err;
}

static int npu_remove(struct platform_device *pdev)
{
	struct npu_shared_info *drvdata = platform_get_drvdata(pdev);

	cleanupModule(drvdata);

	return 0;
}

static int npu_suspend(struct device *dev)
{
	struct npu_shared_info *drvdata = dev_get_drvdata(dev);

	clk_disable(drvdata->clk);
	clk_disable(drvdata->axi_clk);
	clk_disable(drvdata->apb_clk);
	clk_disable(drvdata->pwr_clk);
	return 0;
}

static int npu_resume(struct device *dev)
{
	struct npu_shared_info *drvdata = dev_get_drvdata(dev);

	//reset_npu(drvdata->sysc_regmap);
	clk_enable(drvdata->axi_clk);
	clk_enable(drvdata->apb_clk);
	clk_enable(drvdata->pwr_clk);
	clk_enable(drvdata->clk);

	init_npu(drvdata->hdevinfo);

	return 0;
}

static SIMPLE_DEV_PM_OPS(npu_pm_ops, npu_suspend, npu_resume);

static const struct of_device_id npu_of_match[] = {
	{.compatible = "vatics, npu",},
	{}
};
MODULE_DEVICE_TABLE(of, npu_of_match);

static struct platform_driver npu_driver = {
	.probe = npu_probe,
	.remove = npu_remove,
	.driver = {
		.name = "NPU",
		.owner = THIS_MODULE,
		.pm = &npu_pm_ops,
		.of_match_table = npu_of_match,
	},
};
module_platform_driver(npu_driver);
