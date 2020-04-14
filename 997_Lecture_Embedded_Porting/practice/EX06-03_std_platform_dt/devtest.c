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
#include <linux/gpio.h>

#include "my_ioctl.h"

#define MAX_BUF 26

static unsigned int device_major = 241;
static unsigned int device_minor_start = 0;
static unsigned int device_minor_count = 4;
static dev_t devt;
static struct cdev *my_cdev;

static char rbuf[MAX_BUF];
static char wbuf[MAX_BUF];

#define PAD_PHY_BASE		0x11000000
#define PAD_PHY_SIZE		0x1000
#define GPM4CON			0x2e0
#define GPM4DAT			0x2e4

static volatile unsigned long pad_base;
static struct resource *pad_mem;

#define GPIO_KEY3 215
int irq_key3;
static int irq_enabled = 0;

#define TEST_PLATFORM_DEVICE 1
#if TEST_PLATFORM_DEVICE
#include <linux/platform_device.h>
#define DEVICE_NAME "my_pdev"
#endif

#define TEST_RESOURCES 1
#if TEST_RESOURCES
struct my_platform_config {
        int led_status;
};

static int phy_base;
static int phy_size;
static int irq;
static int irq_flags;
static int led_status;
#endif

#define TEST_DT 1

static void led_init(void)
{
        iowrite32((ioread32((void *)(pad_base+GPM4CON)) & ~(0xff<<16)) | (0x11<<16), (void *)(pad_base+GPM4CON));
        iowrite32(ioread32((void *)(pad_base+GPM4DAT)) & ~(0x3<<4), (void *)(pad_base+GPM4DAT));
}

static void led_on(void)
{
        iowrite32(ioread32((void *)(pad_base+GPM4DAT)) | (0x3<<4), (void *)(pad_base+GPM4DAT));
}

static void led_off(void)
{
        iowrite32(ioread32((void *)(pad_base+GPM4DAT)) & ~(0x3<<4), (void *)(pad_base+GPM4DAT));
}

static long device_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	int ret = 0, data;

	switch(cmd) {
		case MY_IOCTL_CMD_ONE:
			printk("devtest: MY_IOCTL_CMD_ONE\n");
			break;
		case MY_IOCTL_CMD_TWO:
			if(copy_from_user(&data, (int *)arg, sizeof(int))) {
				return -EFAULT;
			}
			printk("devtest: MY_IOCTL_CMD_TWO(%d)\n", data);
			ret = 2;
			break;
		case MY_IOCTL_CMD_LED_ON:
			printk("devtest: MY_IOCTL_CMD_LED_ON\n");
			led_on();
			break;
		case MY_IOCTL_CMD_LED_OFF:
			printk("devtest: MY_IOCTL_CMD_LED_OFF\n");
			led_off();
			break;
		case MY_IOCTL_CMD_IRQ_EN:
			printk("devtest: MY_IOCTL_CMD_IRQ_EN\n");
			if(!irq_enabled) enable_irq(irq_key3);
			irq_enabled = 1;
			break;
		case MY_IOCTL_CMD_IRQ_DIS:
			printk("devtest: MY_IOCTL_CMD_IRQ_DIS\n");
			if(irq_enabled) disable_irq(irq_key3);
			irq_enabled = 0;
			break;
		default:
			printk("devtest: unknown command\n");
			ret = -EINVAL;
			break;
	}

	return ret;
}

static ssize_t device_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	ssize_t rlen; 

	printk("devtest: device_read (minor = %d)\n", iminor(filp->f_path.dentry->d_inode));
	rlen = MAX_BUF;
	if(rlen > count) {
		rlen = count;
	}
	if(copy_to_user(buf, rbuf, rlen)) {
		return -EFAULT;
	}
	printk("devtest: read %d bytes\n", rlen);

	return rlen;
}

static ssize_t device_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	ssize_t wlen;

	printk("devtest: device_write (minor = %d)\n", iminor(filp->f_path.dentry->d_inode));
	wlen = MAX_BUF;
	if(wlen > count) {
		wlen = count;
	}
	if(copy_from_user(wbuf, buf, wlen)) {
		return -EFAULT;
	}
	printk("devtest: wrote %d bytes\n", wlen);
	
	return wlen;
}

static int device_open(struct inode *inode, struct file *filp)
{
	printk("devtest: device_open (minor = %d)\n", iminor(inode));
	return 0;
}

static int device_release(struct inode *inode, struct file *filp)
{
	printk("devtest: device_release\n");
	return 0;
}


static const struct file_operations my_fops = {
	.owner = THIS_MODULE,
	.unlocked_ioctl = device_ioctl,
	.open = device_open,
	.read = device_read,
	.write = device_write,
	.release = device_release,
};

irqreturn_t key_isr(int irq, void *dev_id)
{
	static int count;

	printk("devtest: %s(): count = %d\n", __FUNCTION__, ++count);

	return IRQ_HANDLED;
}

#if TEST_DT
static const struct of_device_id my_pdev_of_match[] = {
        { .compatible = "my-pdev", },
        { },
};
MODULE_DEVICE_TABLE(of, my_pdev_of_match);
#endif

#if TEST_PLATFORM_DEVICE
static int driver_probe(struct platform_device *pdev)
#else
static int __init device_init(void)
#endif
{
	int ret, i;
#if TEST_RESOURCES
        struct resource *res;
        struct my_platform_config *config = pdev->dev.platform_data;
#endif

	printk("devtest: device_init\n");

	devt = MKDEV(device_major, device_minor_start);
	ret = register_chrdev_region(devt, device_minor_count, "my_device");

	if(ret < 0) {
		printk("devtest: can't get major %d\n", device_major);
		return ret;
	}

	my_cdev = cdev_alloc();
	my_cdev->ops = &my_fops;
	my_cdev->owner = THIS_MODULE;
	ret = cdev_add(my_cdev, devt, device_minor_count);
	if(ret) {
		printk("devtest: can't add device %d\n", devt);
		goto err1;
	}

	/* init buffers */
	for(i=0; i<MAX_BUF; i++) rbuf[i] = 'A' + i;
	for(i=0; i<MAX_BUF; i++) wbuf[i] = 0;

#if TEST_RESOURCES
        res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
        if (!res) {
                printk("devtest: can't allocate resource\n");
                ret = -ENODEV;
                goto err2;
        }
        phy_base = res->start;
        phy_size = res->end - res->start;

        res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
        if (!res) {
                printk("devtest: can't allocate resource\n");
                ret = -ENODEV;
                goto err2;
        }
        irq = res->start;
        irq_flags = res->flags & IRQF_TRIGGER_MASK;

#if TEST_DT
	if(!config) {
		struct device *dev = &pdev->dev;

		if(device_property_read_u32(dev, "led_status", &led_status)) {
			goto err1;
		}
	}
	else {
		led_status = config->led_status;
	}
#else
        led_status = config->led_status;
#endif
#endif

#if TEST_RESOURCES
        pad_mem = request_mem_region(phy_base, phy_size, "pad-base");
#else
        pad_mem = request_mem_region(PAD_PHY_BASE, PAD_PHY_SIZE, "pad-base");
#endif
	if (pad_mem == NULL) {
		printk("devtest: failed to get memory region\n");
		ret = -EIO;
		goto err2;
	}

#if TEST_RESOURCES
        pad_base = (unsigned long)ioremap(phy_base, phy_size);
#else
        pad_base = (unsigned long)ioremap(PAD_PHY_BASE, PAD_PHY_SIZE);
#endif
	if (pad_base == 0) {
		printk("devtest: led to ioremap() region\n");
		ret = -EIO;
		goto err3;
	}

#if TEST_RESOURCES
	led_init();
        if(led_status == 0) led_off();
	else led_on();
#else
	led_init();
#endif

#if TEST_RESOURCES
#if TEST_DT
	irq_key3 = irq;
#else
	irq_key3 = gpio_to_irq(irq);
#endif
	if(request_irq(irq_key3, key_isr, irq_flags, "key_int", NULL)) {
		printk("devtest: IRQ %d is not free\n", irq_key3);
		ret = -EIO;
		goto err4;
	}
	printk("devtest: IRQ %d is enabled\n", irq_key3);
#else
	irq_key3 = gpio_to_irq(GPIO_KEY3);
	if(request_irq(irq_key3, key_isr, IRQF_TRIGGER_FALLING, "key_int", NULL)) {
		printk("devtest: IRQ %d is not free\n", irq_key3);
		ret = -EIO;
		goto err4;
	}
	printk("devtest: IRQ %d is enabled\n", irq_key3);
#endif
	irq_enabled = 1;

	return 0;

err4:
	iounmap((void *)pad_base);
err3:
#if TEST_RESOURCES
        release_mem_region(phy_base, phy_size);
#else
        release_mem_region(PAD_PHY_BASE, PAD_PHY_SIZE);
#endif
err2:
	cdev_del(my_cdev);
err1:
	unregister_chrdev_region(devt, device_minor_count);

	return ret;
}

#if TEST_PLATFORM_DEVICE
static int driver_remove(struct platform_device *pdev)
#else
static void __exit device_exit(void)
#endif
{
	free_irq(irq_key3, NULL);
	irq_enabled = 0;
	iounmap((void *)pad_base);
#if TEST_RESOURCES
        release_mem_region(phy_base, phy_size);
#else
        release_mem_region(PAD_PHY_BASE, PAD_PHY_SIZE);
#endif
	cdev_del(my_cdev);
	unregister_chrdev_region(devt, device_minor_count);

	printk("devtest: device_exit\n");

#if TEST_PLATFORM_DEVICE
        return 0;
#endif
}

#if TEST_PLATFORM_DEVICE

#if TEST_DT
#else
static void my_release_device(struct device *dev)
{
        printk("devtest: my_release_device\n");
};

#if TEST_RESOURCES
static struct resource my_resources[] = {
        [0] = {
                .start  = PAD_PHY_BASE,
                .end    = PAD_PHY_BASE + PAD_PHY_SIZE,
                .flags  = IORESOURCE_MEM,
        },
        [1] = {
                .start  = GPIO_KEY3,
                .end    = GPIO_KEY3,
                .flags  = IORESOURCE_IRQ | IRQF_TRIGGER_FALLING,
        },
};

static struct my_platform_config my_config = {
        .led_status = 0,
};

struct platform_device my_platform_device = {
        .name           = DEVICE_NAME,
        .id             = 0,
        .num_resources  = ARRAY_SIZE(my_resources),
        .resource       = my_resources,
        .dev    = {
                .platform_data  = &my_config,
                .release        = my_release_device,
        },
};
#else
struct platform_device my_platform_device = {
        .name           = DEVICE_NAME,
        .id             = 0,
        .num_resources  = 0,
        .dev    = {
                .release        = my_release_device,
        },
};
#endif
#endif

static int driver_suspend(struct platform_device *pdev, pm_message_t pm)
{
        return 0;
}

static int driver_resume(struct platform_device *pdev)
{
        return 0;
}

static struct platform_driver my_platform_driver = {
        .probe          = driver_probe,
        .remove         = driver_remove,
        .suspend        = driver_suspend,
        .resume         = driver_resume,
        .driver         = {
                .name   = DEVICE_NAME,
                .owner  = THIS_MODULE,
#if TEST_DT
		.of_match_table = my_pdev_of_match,
#endif
        },
};

static int __init platform_device_init(void)
{
        int ret;

        printk("devtest: platform_device_init\n");

#if TEST_DT
        ret = platform_driver_register(&my_platform_driver);
        if(ret) {
                printk("platform_driver_register failed (ret=%d) \n", ret);
        }
#else
        ret = platform_device_register(&my_platform_device);
        if(ret) {
                printk("platform_device_register failed (ret=%d) \n", ret);
                return ret;
        }

        ret = platform_driver_register(&my_platform_driver);
        if(ret) {
                platform_device_unregister(&my_platform_device);
                printk("platform_driver_register failed (ret=%d) \n", ret);
        }
#endif

        return ret;
}

static void __exit platform_device_exit(void)
{
        platform_driver_unregister(&my_platform_driver);
#if TEST_DT
#else
        platform_device_unregister(&my_platform_device);
#endif
        printk("devtest: platform_device_exit\n");
}

module_init(platform_device_init);
module_exit(platform_device_exit);

#else

module_init(device_init);
module_exit(device_exit);

#endif

MODULE_LICENSE("GPL");
