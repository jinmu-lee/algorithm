#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/cdev.h>

static unsigned int device_major = 241;
static unsigned int device_minor_start = 0;
static unsigned int device_minor_count = 4;
static dev_t devt;
static struct cdev *my_cdev;

static int device_open(struct inode *inode, struct file *filp)
{
	printk("device_open (minor = %d)\n", /* Implement code */);
	return 0;
}

static int device_release(struct inode *inode, struct file *filp)
{
	printk("device_release\n");
	return 0;
}

static const struct file_operations my_fops = {
	.owner = THIS_MODULE,
	/* Implement code */
};

static int __init device_init(void)
{
	int ret;

	printk("device_init\n");

	devt = MKDEV(device_major, device_minor_start);
	ret = register_chrdev_region(devt, device_minor_count, "my_device");
	if(ret < 0) {
		printk("can't get major %d\n", device_major);
		return ret;
	}

	my_cdev = cdev_alloc();
	my_cdev->ops = &my_fops;
	my_cdev->owner = THIS_MODULE;
	ret = cdev_add(my_cdev, devt, device_minor_count);
	if(ret) {
		printk("can't add device %d\n", devt);
		unregister_chrdev_region(devt, device_minor_count);
		return ret;
	}

	return 0;
}

static void __exit device_exit(void)
{
	cdev_del(my_cdev);
	unregister_chrdev_region(devt, device_minor_count);
	printk("device_exit\n");
}

module_init(device_init);
module_exit(device_exit);

MODULE_LICENSE("GPL");

