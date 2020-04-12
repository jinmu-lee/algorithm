#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/timer.h>

MODULE_LICENSE("GPL");

static struct timer_list timer;

void my_timer_handler(unsigned long data)
{
	printk("my_timer_handler(%lu)\n", data );
}

int my_init(void)
{
	printk("my_init()\n");
	init_timer(&timer);
	timer.expires  = jiffies + 3*HZ;
	timer.function = my_timer_handler;
	timer.data     = 0;
	add_timer(&timer);
	return 0;
}

void my_exit(void)
{
	printk("my_exit()\n");
	del_timer(&timer);
}

module_init( my_init );
module_exit( my_exit );
