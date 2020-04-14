#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/errno.h>
#include <linux/uaccess.h>
#include <linux/delay.h>
#include <linux/ioport.h>
#include <asm/io.h>
#include <linux/interrupt.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/gpio.h>

#define TEST_WAITQUEUE 1

#include "my_ioctl.h"

#include <linux/platform_device.h>
#define MYADC_NAME "myadc_dev"

#define ADC_PHY_BASE 0x126C0000
#define ADC_PHY_SIZE 0x100

#define ADCCON 0x0000
#define ADCDLY 0x0008
#define ADCDAT 0x000C
#define CLRINTADC 0x0018
#define ADCMUX 0x001C

static unsigned int device_major = 241;
static unsigned int device_minor_start = 0;
static unsigned int device_minor_count = 4;

static struct my_data {
	struct cdev cdev;

	resource_size_t phy_base;
	resource_size_t phy_size;
	int irq;
	volatile unsigned long adc_base;
	struct resource *adc_mem;

	int max_cnt;
	int adc_cnt;
	int adc_sum;
	int adc_average;

	int my_flag;
#if TEST_WAITQUEUE
	wait_queue_head_t my_waitqueue;
#endif

} *my_pdata;

struct myadc_platform_config {
	int max_cnt;
};

irqreturn_t adc_isr(int irq, void *dev_id)
{
	struct my_data *pdata = (struct my_data *)dev_id;
	int adc_val;

	iowrite32(0x00, (void *)(pdata->adc_base+CLRINTADC));

	if(pdata->adc_cnt >= pdata->max_cnt) return IRQ_HANDLED;
	adc_val = ioread32((void *)(pdata->adc_base+ADCDAT)) & 0xfff;

	pdata->adc_sum += adc_val;
	pdata->adc_cnt++;
	if(pdata->adc_cnt == pdata->max_cnt) {
		pdata->adc_average = pdata->adc_sum / pdata->max_cnt;

		pdata->my_flag = 1;
#if TEST_WAITQUEUE
		/* Implement code */
#endif
	}

	return IRQ_HANDLED;
}

void adc_isr_start(struct my_data *pdata)
{
	int temp;

	iowrite32((1<<16)|(1<<14)|(255<<6)|(1<<1), (void *)(pdata->adc_base+ADCCON));
	iowrite32(0x7fff, (void *)(pdata->adc_base+ADCDLY));
	iowrite32(0x00, (void *)(pdata->adc_base+ADCMUX));
	iowrite32(0x00, (void *)(pdata->adc_base+CLRINTADC));

	pdata->adc_cnt = 0;
	pdata->adc_sum = 0;
	temp = ioread32((void *)(pdata->adc_base+ADCDAT));
}

static long device_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	struct my_data *pdata = filp->private_data;
	int ret = 0, data;

	switch(cmd) {
		case MY_IOCTL_CMD_SET_MAX_COUNT:
			printk("myadc: MY_IOCTL_CMD_SET_MAX_COUNT\n");
			if(copy_from_user(/* Implement code */)) {
				return -EFAULT;
			}
			pdata->max_cnt = data;

			break;
		default:
			printk("myadc: unknown command\n");
			ret = -EINVAL;
			break;
	}

	return ret;
}

static ssize_t device_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	struct my_data *pdata = filp->private_data;

	printk("myadc: device_read (minor = %d)\n", iminor(filp->f_path.dentry->d_inode));

	pdata->my_flag = 0;
	adc_isr_start(pdata);
	printk("myadc: waiting event\n");
#if TEST_WAITQUEUE
	if(wait_event_interruptible(/* Implement code */)) {
		printk("myadc: interrupted\n");
		return -ERESTARTSYS;
	}
#else
	while(pdata->my_flag == 0);
#endif

	if(copy_to_user(buf, &pdata->adc_average, sizeof(int))) {
		return -EFAULT;
	}

	return sizeof(int);
}

static int device_open(struct inode *inode, struct file *filp)
{
	struct my_data *pdata;

	printk("myadc: device_open (minor = %d)\n", iminor(inode));

	pdata = container_of(inode->i_cdev, struct my_data, cdev);
	filp->private_data = pdata;

	return 0;
}

static int device_release(struct inode *inode, struct file *filp)
{
	printk("myadc: device_release\n");

	return 0;
}

static const struct file_operations my_fops = {
	.owner = THIS_MODULE,
	.unlocked_ioctl = device_ioctl,
	.open = device_open,
	.release = device_release,
	.read = device_read,
};

static int driver_probe(struct platform_device *pdev)
{
	int ret;
	dev_t devt;
	struct my_data *pdata;

	struct resource *res;
	struct myadc_platform_config *config = pdev->dev.platform_data;

	printk("myadc: device_init\n");

	devt = MKDEV(device_major, device_minor_start);
	ret = register_chrdev_region(devt, device_minor_count, "myadc_device");
	if(ret < 0) {
		printk("myadc: can't get major %d\n", device_major);
		return ret;
	}

	my_pdata = kmalloc(sizeof(struct my_data), GFP_KERNEL);
	if(!my_pdata) {
		ret = -ENOMEM;
		goto err1;
	}
	pdata = my_pdata;
	memset(pdata, 0, sizeof(struct my_data));


	cdev_init(&pdata->cdev, &my_fops);
	pdata->cdev.owner = THIS_MODULE;
	ret = cdev_add(&pdata->cdev, devt, 1);
	if(ret) {
		printk("myadc: can't add device %d\n", devt);
		goto err2;
	}

#if TEST_WAITQUEUE
	init_waitqueue_head(&pdata->my_waitqueue);
#endif

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		printk("myadc: can't allocate resource\n");
		ret = -ENODEV;
		goto err3;
	}
	pdata->phy_base = res->start;
	pdata->phy_size = res->end - res->start;

	res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
	if (!res) {
		printk("myadc: can't allocate resource\n");
		ret = -ENODEV;
		goto err3;
	}
	pdata->irq = res->start;

        if(!config) {
                struct device *dev = &pdev->dev;

                if(device_property_read_u32(/* Implement code */)) {
                        goto err3;
                }
        }
	else {
		pdata->max_cnt = config->max_cnt;
	}

	pdata->adc_mem = request_mem_region(pdata->phy_base, pdata->phy_size, "adc-base");
	if (pdata->adc_mem == NULL) {
		printk("myadc: failed to get memory region\n");
		ret = -EIO;
		goto err3;
	}

	pdata->adc_base = (unsigned long)ioremap(pdata->phy_base, pdata->phy_size);
	if (pdata->adc_base == 0) {
		printk("myadc: led to ioremap() region\n");
		ret = -EIO;
		goto err4;
	}

	if(request_irq(pdata->irq, adc_isr, 0, "adc_int", pdata)) {
		printk("myadc: IRQ %d is not free\n", pdata->irq);
		ret = -EIO;
		goto err5;
	}
	printk("myadc: IRQ %d is enabled\n", pdata->irq);

	return 0;

err5:
	iounmap((void *)pdata->adc_base);
err4:
	release_mem_region(pdata->phy_base, pdata->phy_size);
err3:
	cdev_del(&pdata->cdev);
err2:
	kfree(pdata);
err1:
	unregister_chrdev_region(devt, device_minor_count);

	return ret;
}

static int driver_remove(struct platform_device *pdev)
{
	dev_t devt;
	struct my_data *pdata = my_pdata;

	devt = MKDEV(device_major, device_minor_start);
	free_irq(pdata->irq, pdata);
	iounmap((void *)pdata->adc_base);
	release_mem_region(pdata->phy_base, pdata->phy_size);
	cdev_del(&pdata->cdev);
	kfree(pdata);
	unregister_chrdev_region(devt, device_minor_count);

	printk("myadc: device_exit\n");

	return 0;
}

static int driver_suspend(struct platform_device *pdev, pm_message_t pm)
{
	return 0;
}

static int driver_resume(struct platform_device *pdev)
{
	return 0;
}

static const struct of_device_id myadc_dev_of_match[] = {

	/* Implement code */

};
MODULE_DEVICE_TABLE(of, myadc_dev_of_match);

static struct platform_driver myadc_driver = {
	.probe          = driver_probe,
	.remove         = driver_remove,
	.suspend        = driver_suspend,
	.resume         = driver_resume,
	.driver         = {
		.name   = MYADC_NAME,
		.owner  = THIS_MODULE,
		.of_match_table = myadc_dev_of_match,
	},
};

static int __init platform_device_init(void)
{
	int ret;

	printk("myadc: platform_device_init\n");

        ret = platform_driver_register(&myadc_driver);
        if(ret) {
                printk("myadc: platform_driver_register failed (ret=%d) \n", ret);
        }

	return ret;
}

static void __exit platform_device_exit(void)
{
	platform_driver_unregister(&myadc_driver);
	printk("myadc: platform_device_exit\n");
}

module_init(platform_device_init);
module_exit(platform_device_exit);

MODULE_LICENSE("GPL");
