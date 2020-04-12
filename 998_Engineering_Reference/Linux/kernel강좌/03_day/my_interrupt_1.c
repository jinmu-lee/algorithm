#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/gpio.h>

MODULE_LICENSE("GPL");

irqreturn_t my_irq_handler(int irq, void *id)
{
	int value;
	value = gpio_get_value(170);
	if( value == 0 )
		printk("my_irq_handler(%d, %p), Pressed\n", irq, id );
	else
		printk("my_irq_handler(%d, %p), Released\n", irq, id );
	return IRQ_HANDLED;
}

static int temp;
static void *dev = &temp;
static unsigned long flags = 0x83;
int my_init(void)
{
	int ret;
	printk("my_init()\n");
	ret = request_irq(379, my_irq_handler,flags,"MY INT 1",dev);
	return 0;
}

void my_exit(void)
{
	printk("my_exit()\n");
	free_irq(379, dev);
}

module_init( my_init );
module_exit( my_exit );
