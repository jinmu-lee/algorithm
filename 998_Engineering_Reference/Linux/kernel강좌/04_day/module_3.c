#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

int my_init(void)
{
	printk("my_init()\n");
	return 0;
}

void my_exit(void)
{
	printk("my_exit()\n");
}

module_init( my_init );
module_exit( my_exit );
