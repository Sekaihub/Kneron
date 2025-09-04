// SPDX-License-Identifier: GPL-2.0-only
/*
 *
 * Copyright (C) 2022 VATICS Inc.
 *
 */
#include "ie_driver.h"

#define SYSC_RST0_SET 0x158
#define SYSC_RST0_CLR 0x15c
#define SYSC_RST1_SET 0x160
#define SYSC_RST1_CLR 0x164

static unsigned int gsdwMajor = 194;

MODULE_AUTHOR("VATICS Inc.");
MODULE_LICENSE("GPL");
module_param(gsdwMajor, int, 0644);
MODULE_PARM_DESC(gsdwMajor, "Major number for IE module");

static void reset_ie(struct ie_shared_info *shared_info)
{
	struct regmap *regmap = shared_info->sysc_regmap;
	unsigned int id = shared_info->id;

	if (id == 0) {
		/*
		 * RST0:
		 *     - BIT29:APB
		 *     - BIT30:AXI
		 */
		regmap_write(regmap, SYSC_RST0_CLR, 0x60000000);
		regmap_write(regmap, SYSC_RST0_SET, 0x60000000);
	} else {
		/*
		 * RST1:
		 *     - BIT24:APB
		 *     - BIT25:AXI
		 */
		regmap_write(regmap, SYSC_RST1_CLR, 0x03000000);
		regmap_write(regmap, SYSC_RST1_SET, 0x03000000);
	}
}

static void __maybe_unused dump_ie_info(struct ie_info *info)
{
	pr_info("index = %d\n", info->index);
	pr_info("phy inst_addr = %p\n", info->inst_addr);
	pr_info("virt inst_addr = %p\n", info->inst_virt_addr);
	pr_info("inst size  = %d\n", info->inst_size);
	pr_info("phy src_addr = %p\n", info->src_addr);
	pr_info("virt src_addr = %p\n", info->src_virt_addr);
	pr_info("src size  = %d\n", info->src_size);
	pr_info("phy dst_addr = %p\n", info->dst_addr);
	pr_info("virt dst_addr = %p\n", info->dst_virt_addr);
	pr_info("dst size  = %d\n", info->dst_size);
}

static void __maybe_unused dump_cmdbuf_virt_addr(struct cmd_buf *cmd)
{
	pr_info("dump cmdbuf virt info\n");
	pr_info("inst_kvirt_addr = %p\n", cmd->inst_kvirt_addr);
	pr_info("src_kvirt_addr = %p\n", cmd->src_kvirt_addr);
	pr_info("dst_kvirt_addr = %p\n", cmd->dst_kvirt_addr);
}

static int ie_remap_buf(struct ie_info *info, struct cmd_buf *cmd)
{
	//dump_npu_info(info);
	cmd->inst_kvirt_addr = memremap((resource_size_t)info->inst_addr,
					info->inst_size, MEMREMAP_WB);
	if (!cmd->inst_kvirt_addr) {
		pr_err("inst remap failed\n");
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

static void ie_unmap_buf(struct cmd_queue *cmdqueue)
{
	unsigned int i = 0;
	struct cmd_buf *cmd;

	for (i = 0; i < cmdqueue->cmdbuf_num; ++i) {
		cmd = cmdqueue->cmdbuf[i];

		memunmap(cmd->inst_kvirt_addr);
		memunmap(cmd->src_kvirt_addr);
		memunmap(cmd->dst_kvirt_addr);
	}
}

static void ie_free_cmdbuf(struct cmd_queue *cmdqueue)
{
	unsigned int i = 0;
	struct cmd_buf *cmd;

	for (i = 0; i < cmdqueue->cmdbuf_num; ++i) {
		cmd = cmdqueue->cmdbuf[i];
		kfree(cmd->ieinfo);
		kfree(cmd);
	}
}
static int cmd_done(struct ie_shared_info *ie_dev)
{
	struct cmd_buf *cmdbuf;
	unsigned long flags;
	struct ie_obj_info *obj_info;
	unsigned int ret = 0;

	spin_lock_irqsave(&(ie_dev->fh_lock), flags);
	obj_info = ie_dev->curr_obj;
	--obj_info->obj_cmdqueue.cmd_queued_count;
	spin_unlock_irqrestore(&(ie_dev->fh_lock), flags);

	spin_lock_irqsave(&obj_info->obj_cmdqueue.cmd_queue_lock, flags);
	cmdbuf = list_first_entry(&obj_info->obj_cmdqueue.cmd_queued_list,
				  struct cmd_buf, queued_entry);
	list_add_tail(&cmdbuf->done_entry,
		      &obj_info->obj_cmdqueue.cmd_done_list);
	list_del(&cmdbuf->queued_entry);
	spin_unlock_irqrestore(&obj_info->obj_cmdqueue.cmd_queue_lock, flags);

	return ret;
}

static int sel_the_next_cmd(struct ie_shared_info *ie_dev,
		struct ie_obj_info **cur_obj)
{
	struct ie_obj_info *obj_info, *next_obj_info = NULL;
	int ret = 0;
	unsigned int found = 0;

	obj_info = *cur_obj;
	next_obj_info = *cur_obj;

	if (list_is_singular(&ie_dev->fh_list)) {
		if (next_obj_info->obj_cmdqueue.cmd_queued_count)
			found = 1;
	} else {
		list_for_each_entry_continue(next_obj_info,
					     &ie_dev->fh_list, list) {
			if (next_obj_info->obj_cmdqueue.cmd_queued_count) {
				found = 1;
				break;
			}
		}

		if (!found) {
			next_obj_info = *cur_obj;
			list_for_each_entry_continue_reverse(next_obj_info,
							     &ie_dev->fh_list,
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

static irqreturn_t ie_isr(int irq, void *dev_id)
{
	struct ie_obj_info *obj_info = NULL;
	struct ie_shared_info *ie_dev = dev_id;
	struct ie_obj_info *wakeup_obj_info = NULL;
	struct cmd_buf *cmdbuf;
	unsigned long flags;

	spin_lock_irqsave(&ie_dev->isr_lock, flags);
	obj_info = ie_dev->curr_obj;
	wakeup_obj_info = ie_dev->curr_obj;
	ie_isrhead(ie_dev->hdevinfo);

	cmd_done(ie_dev);

	cmdbuf = list_last_entry(&obj_info->obj_cmdqueue.cmd_done_list,
				  struct cmd_buf, done_entry);

	cmdbuf->ieinfo->profile = ie_read_op_cycle(ie_dev->hdevinfo);

	sel_the_next_cmd(ie_dev, &obj_info);
	cmdbuf = list_first_entry(&obj_info->obj_cmdqueue.cmd_queued_list,
				  struct cmd_buf, queued_entry);
	if (!obj_info->obj_cmdqueue.cmd_queued_count) {
		ie_isrtail(ie_dev->hdevinfo, NULL);
		ie_dev->curr_obj = NULL;
	} else {
		ie_isrtail(ie_dev->hdevinfo, cmdbuf);
		ie_dev->curr_obj = obj_info;
	}

	spin_unlock_irqrestore(&ie_dev->isr_lock, flags);
	wake_up(&wakeup_obj_info->obj_cmdqueue.cmd_done_wq);
	return IRQ_HANDLED;
}

static int start(struct ie_obj_info *objinfo, struct ie_info *ieinfo)
{
	unsigned int writeindex = 0;
	struct ie_shared_info *dev_info = objinfo->dev_info;
	unsigned long flags;
	unsigned long isr_flags;
	struct cmd_queue *cmdqueue = &objinfo->obj_cmdqueue;
	struct cmd_buf *cmdbuf;

	if (!cmdqueue->cmdbuf_num) {
		cmdbuf = kzalloc(sizeof(struct cmd_buf), GFP_KERNEL);
		cmdbuf->ieinfo = kzalloc(sizeof(struct ie_info), GFP_KERNEL);
	} else
		cmdbuf = cmdqueue->cmdbuf[ieinfo->index];
	memcpy(cmdbuf->ieinfo, ieinfo, sizeof(struct ie_info));

	ie_starthead(dev_info->hdevinfo);

	spin_lock_irqsave(&dev_info->isr_lock, isr_flags);
	spin_lock_irqsave(&(cmdqueue->cmd_queue_lock), flags);
	list_add_tail(&cmdbuf->queued_entry,
		      &objinfo->obj_cmdqueue.cmd_queued_list);
	++objinfo->obj_cmdqueue.cmd_queued_count;
	if (!ie_is_busy(dev_info->hdevinfo))
		dev_info->curr_obj = objinfo;

	ie_starttail(dev_info->hdevinfo,
		      writeindex, cmdbuf);
	spin_unlock_irqrestore(&(cmdqueue->cmd_queue_lock), flags);
	spin_unlock_irqrestore(&dev_info->isr_lock, isr_flags);

	return 0;
}

static int reset_queue(struct ie_obj_info *objinfo)
{
	struct ie_shared_info *dev_info = objinfo->dev_info;
	struct cmd_queue *cmdqueue = &objinfo->obj_cmdqueue;
	unsigned long flags;
	unsigned int ret = 0;
	struct cmd_buf *pos, *node;

	spin_lock_irqsave(&(dev_info->fh_lock), flags);

	/*remove done_list*/
	if (!list_empty(&cmdqueue->cmd_done_list)) {
		list_for_each_entry_safe(pos, node,
				&cmdqueue->cmd_done_list, done_entry)
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

static int waitcomplete(struct ie_obj_info *objinfo)
{
	int ret = 0;
	struct cmd_buf *cmdbuf;
	struct ie_shared_info *dev_info = objinfo->dev_info;
	unsigned long flags;

	if (dev_info->wait_timeout != 0) {
		ret = wait_event_timeout(objinfo->obj_cmdqueue.cmd_done_wq,
			!list_empty(&objinfo->obj_cmdqueue.cmd_done_list),
			dev_info->wait_timeout * HZ);
		if (ret != 0) {
			/* remove done cmd*/
			spin_lock_irqsave(&dev_info->isr_lock, flags);
			cmdbuf = list_first_entry(
					&objinfo->obj_cmdqueue.cmd_done_list,
					struct cmd_buf, done_entry);
			list_del(&cmdbuf->done_entry);
			spin_unlock_irqrestore(&dev_info->isr_lock, flags);
			if (!objinfo->obj_cmdqueue.cmdbuf_num) {
				kfree(cmdbuf->ieinfo);
				kfree(cmdbuf);
			}
		} else
			reset_queue(objinfo);
	} else {
		wait_event(objinfo->obj_cmdqueue.cmd_done_wq,
			   !list_empty(&objinfo->obj_cmdqueue.cmd_done_list));
		/* remove done cmd*/
		spin_lock_irqsave(&dev_info->isr_lock, flags);
		cmdbuf = list_first_entry(&objinfo->obj_cmdqueue.cmd_done_list,
					  struct cmd_buf, done_entry);
		list_del(&cmdbuf->done_entry);
		spin_unlock_irqrestore(&dev_info->isr_lock, flags);
		if (!objinfo->obj_cmdqueue.cmdbuf_num) {
			kfree(cmdbuf->ieinfo);
			kfree(cmdbuf);
		}
		ret = 1;
	}

	return ret;
}

static int close(struct inode *inode, struct file *file)
{
	struct ie_obj_info *objinfo = file->private_data;
	struct ie_shared_info *dev_info = objinfo->dev_info;
	struct cmd_queue *cmdqueue = &objinfo->obj_cmdqueue;

	file->private_data = NULL;

	mutex_lock(&dev_info->ioctl_lock);
	list_del_init(&objinfo->list);
	list_del_init(&objinfo->obj_cmdqueue.cmd_queued_list);
	list_del_init(&objinfo->obj_cmdqueue.cmd_done_list);
	dev_info->total_obj_num--;
	dev_info->open_count--;
	if (!cmdqueue->disable_remapping)
		ie_unmap_buf(cmdqueue);
	ie_free_cmdbuf(cmdqueue);
	mutex_unlock(&dev_info->ioctl_lock);
	kfree(objinfo);

	return 0;
}

static int open(struct inode *inode, struct file *file)
{
	struct ie_obj_info *objinfo;

	struct ie_shared_info *dev = container_of(inode->i_cdev,
						struct ie_shared_info, chrdev);

	if (file->private_data == NULL) {
		file->private_data = kmalloc(sizeof(struct ie_obj_info),
					     GFP_KERNEL);
		if (!file->private_data)
			return -ENOMEM;

		objinfo = (struct ie_obj_info *)file->private_data;

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
		ie_open(dev->hdevinfo);

	dev->open_count++;
	mutex_unlock(&dev->ioctl_lock);

	return 0;
}

static long ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	struct ie_obj_info *objinfo = file->private_data;
	unsigned int dwVersionNum;
	int scError;
	struct ie_info ieinfo;
	struct cmd_buf cmdbuf;
	struct cmd_buf *tmp_cmdbuf;
	struct ie_shared_info *dev_info = objinfo->dev_info;
	struct cmd_queue *cmdqueue = &objinfo->obj_cmdqueue;
	unsigned int i = 0;
	unsigned int timeout = 0;
	struct ie_req_cmd_buf req_buf;

	if (file->private_data == NULL) {
		pr_err("Device does not exist !!\n");
		return -ENODEV;
	}

	if ((_IOC_TYPE(cmd) != IE_IOC_MAGIC) ||
	     (_IOC_NR(cmd) > IE_IOC_MAX_NUMBER)) {
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
	case IE_IOC_START:
		scError = copy_from_user(&ieinfo, (unsigned int *)arg,
					sizeof(struct ie_info));
		cmdbuf.ieinfo = &ieinfo;
		mutex_lock(&dev_info->ioctl_lock);
		if (start(objinfo, &ieinfo) != 0) {
			pr_err("Exit Ioctl function !!\n");
			scError = -1;
		}
		mutex_unlock(&dev_info->ioctl_lock);
	break;
	case IE_IOC_WAIT_COMPLETE:
		scError = copy_from_user(&ieinfo, (unsigned int *)arg,
						sizeof(struct ie_info));

		if (waitcomplete(objinfo) == 0) {
			pr_err("Wait complete timeout !!\n");
			scError = -ETIME;
			break;
		}
		if (!cmdqueue->cmdbuf_num)
			ieinfo.profile = ie_read_op_cycle(dev_info->hdevinfo);
		else {
			tmp_cmdbuf = cmdqueue->cmdbuf[ieinfo.index];
			ieinfo.profile = tmp_cmdbuf->ieinfo->profile;
		}
		scError = copy_to_user((unsigned int *)arg,
					&ieinfo, sizeof(struct ie_info));
		if (scError != 0) {
			pr_err("Exit Ioctl function !!\n");
			scError = -EFAULT;
		}
	break;
	case IE_IOC_REQ_BUF:
		scError = copy_from_user(&req_buf, (unsigned int *)arg,
					sizeof(struct ie_req_cmd_buf));

		if (req_buf.buf_num > IE_MAX_CMDBUF) {
			pr_err("buf_num isn't larger than %d !!\n",
				IE_MAX_CMDBUF);
			scError = -EFAULT;
			break;
		}
		for (i = 0; i < req_buf.buf_num; ++i) {
			scError = copy_from_user(&ieinfo, req_buf.buf_info[i],
					sizeof(struct ie_info));
			cmdqueue->cmdbuf[i] = kmalloc(sizeof(struct cmd_buf),
						      GFP_KERNEL);
			tmp_cmdbuf = cmdqueue->cmdbuf[i];
			tmp_cmdbuf->ieinfo = kzalloc(sizeof(struct ie_info),
						     GFP_KERNEL);
			memcpy(tmp_cmdbuf->ieinfo, &ieinfo,
			       sizeof(struct ie_info));
			ieinfo.index = i;
			if (!cmdqueue->disable_remapping)
				ie_remap_buf(&ieinfo, cmdqueue->cmdbuf[i]);
			scError = copy_to_user(req_buf.buf_info[i],
					       &ieinfo,
					       sizeof(struct ie_info));
		}
		cmdqueue->cmdbuf_num = req_buf.buf_num;
	break;
	case IE_IOC_GET_VERSION_NUMBER:
		dwVersionNum = IE_VERSION;
		scError = copy_to_user((unsigned int *)arg,
					&dwVersionNum,
					sizeof(unsigned int));
		if (scError != 0) {
			pr_err("Exit Ioctl function !!\n");
			scError = -EFAULT;
		}
	break;
	case IE_IOC_CONFIG_ADDR:
		scError = copy_from_user(&ieinfo, (unsigned int *)arg,
					sizeof(struct ie_info));
		config_ie_base(dev_info->hdevinfo,
				(uint32_t)(uint64_t)ieinfo.src_addr,
				(uint32_t)(uint64_t)ieinfo.dst_addr,
				(uint32_t)(uint64_t)ieinfo.inst_addr);
	break;
	case IE_IOC_RESET_IE:
		pr_debug("Reset IE\n");
		reset_ie(dev_info);
		init_ie(dev_info->hdevinfo);
	break;
	case IE_IOC_CONFIG_TIMEOUT:
		scError = copy_from_user(&timeout, (unsigned int *)arg,
					sizeof(unsigned int));
		if (ie_is_busy(dev_info->hdevinfo)) {
			scError = -EBUSY;
			pr_info("NPU is busy\n");
		} else
			dev_info->wait_timeout = timeout;
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

static const struct file_operations ie_fops = {
	.owner = THIS_MODULE,
	.unlocked_ioctl = ioctl,
	.mmap = mmap,
	.open = open,
	.release = close,
};

static void cleanupModule(struct ie_shared_info *shared_info)
{
	if (shared_info != NULL) {
		if (shared_info->hdevinfo != NULL) {
			if (gsdwMajor != 0) {
				vma_unregister_device(MKDEV(gsdwMajor, 0));
				unregister_chrdev(gsdwMajor, "ie");
			}

			kfree(shared_info->hdevinfo);
		}

		kfree(shared_info);
	}
}

static int ie_probe(struct platform_device *pdev)
{
	int err;
	int ret;
	unsigned int dwDevInfoSize, dwVersionNum;
	struct resource *res;
	struct device *dev = &pdev->dev;
	phys_addr_t base_addr;
	int virq;
	dev_t dev_id;
	struct ie_shared_info *shared_info;
	uint8_t dev_name[80];
	int id;

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

	shared_info = devm_kzalloc(&pdev->dev, sizeof(struct ie_shared_info),
					GFP_KERNEL);
	if (!shared_info) {
		err = -ENOMEM;
		goto FAIL;
	}

	dwDevInfoSize = ie_getdevinfosize();

	shared_info->hdevinfo = kmalloc(dwDevInfoSize, GFP_KERNEL);
	if (!shared_info->hdevinfo) {
		err = -ENOMEM;
		goto FAIL;
	}
	memset(shared_info->hdevinfo, 0, dwDevInfoSize);

	mutex_init(&shared_info->ioctl_lock);

	shared_info->irq = virq;
	shared_info->mmr_addr = base_addr;
	shared_info->dev = dev;
	shared_info->total_obj_num = 0;

	shared_info->sysc_regmap = sysc_regmap;

	ret = of_property_read_u32(pdev->dev.of_node, "id", &id);
	if (ret) {
		err = -ENODEV;
		return err;
	}

	shared_info->id = id;
	reset_ie(shared_info);

	if (id != 0)
		shared_info->clk = devm_clk_get(dev, "ieu_1_axi");
	else
		shared_info->clk = devm_clk_get(dev, "ieu_0_axi");
	if (IS_ERR(shared_info->clk))
		return PTR_ERR(shared_info->clk);

	clk_prepare_enable(shared_info->clk);
	ret = clk_prepare_enable(shared_info->clk);
	if (ret < 0)
		return ret;

	platform_set_drvdata(pdev, shared_info);

	//request_mem_region(base_addr, resource_size(res), "IE");

	ret = ie_setmmrinfo(shared_info->hdevinfo,
			     reg_base,
			     shared_info->clk,
			     NULL);
	if (ret) {
		err = -ENODEV;
		goto FAIL;
	}

	if (id != 0)
		snprintf(dev_name, 6, "ie%d", id);
	else
		snprintf(dev_name, 6, "ie");
	err = alloc_chrdev_region(&dev_id, 0, /* minor start */
				  1,
				  dev_name);
	gsdwMajor = MAJOR(dev_id);
	cdev_init(&shared_info->chrdev, &ie_fops);
	err = cdev_add(&shared_info->chrdev, dev_id, 1);

	if (err < 0) {
		pr_err("Cannot get major number %d !!\n", (int)gsdwMajor);
		goto FAIL;
	}

	if (gsdwMajor == 0)
		gsdwMajor = err;

	vma_register_device(MKDEV(gsdwMajor, 0), NULL, dev_name);

	dwVersionNum = ie_getversion(shared_info->hdevinfo);

	INIT_LIST_HEAD(&shared_info->fh_list);
	spin_lock_init(&shared_info->fh_lock);

	err = request_irq(shared_info->irq,
			  &ie_isr,
			  IRQF_TRIGGER_HIGH,
			  "ie",
			  shared_info);

	init_ie(shared_info->hdevinfo);

	return 0;

FAIL:
	cleanupModule(shared_info);
	pr_info("Exit InitialModule function !!\n");

	return err;
}

static int ie_remove(struct platform_device *pdev)
{
	struct ie_shared_info *drvdata = platform_get_drvdata(pdev);

	cleanupModule(drvdata);

	return 0;
}

static int ie_suspend(struct device *dev)
{
	struct ie_shared_info *drvdata = dev_get_drvdata(dev);

	clk_disable(drvdata->clk);
	return 0;
}

static int ie_resume(struct device *dev)
{
	struct ie_shared_info *drvdata = dev_get_drvdata(dev);

	reset_ie(drvdata);
	clk_enable(drvdata->clk);

	init_ie(drvdata->hdevinfo);

	return 0;
}

static SIMPLE_DEV_PM_OPS(ie_pm_ops, ie_suspend, ie_resume);

static const struct of_device_id ie_of_match[] = {
	{.compatible = "vatics, ie",},
	{}
};
MODULE_DEVICE_TABLE(of, ie_of_match);

static struct platform_driver ie_driver = {
	.probe = ie_probe,
	.remove = ie_remove,
	.driver = {
		.name = "IE",
		.owner = THIS_MODULE,
		.pm = &ie_pm_ops,
		.of_match_table = ie_of_match,
	},
};
module_platform_driver(ie_driver);
