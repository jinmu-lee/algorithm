#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/fs.h>

#if 1 /* fixed */
unsigned int device_major = 241;
#else /* auto */
unsigned int device_major = 0;
#endif
unsigned int device_minor_start = 0;
unsigned int device_minor_count = 4;
dev_t devt;

static int __init device_init(void)
{
	int ret;

	printk("device_init\n");

	if(device_major) {
		devt = MKDEV(device_major, device_minor_start);
		ret = /* Implement code */ 
	}
	else {
		ret = /* Implement code */
		device_major = MAJOR(devt);
	}

	if(ret < 0) {
		printk("can't get major %d\n", device_major);
		return ret;
	}

	return 0;

}

static void __exit device_exit(void)
{
	unregister_chrdev_region(devt, device_minor_count);
	printk("device_exit\n");
}

module_init(device_init);
module_exit(device_exit);

MODULE_LICENSE("GPL");

