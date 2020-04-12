#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <linux/workqueue.h>

MODULE_LICENSE("GPL");

typedef struct
{
	int gpio;
	int active_low;
	struct work_struct work;
} DEV_INFO;

irqreturn_t my_irq_handler(int irq, void *id)
{
	DEV_INFO *dev_info;
	dev_info = (DEV_INFO*)id;
	printk("my_irq_handler(%d, %p)\n", irq, id );
	schedule_work(&dev_info->work);
	return IRQ_HANDLED;
}

void my_work_handler(struct work_struct *work)
{
	int value;
	DEV_INFO *dev_info;
	dev_info = container_of(work, DEV_INFO, work);
	value = gpio_get_value( dev_info->gpio );
	value = value ^ dev_info->active_low;
	if( value == 1 )
		printk("my_work_handler(%p), Pressed\n", work);
	else
		printk("my_work_handler(%p), Released\n", work );
}

static DEV_INFO dev_info = { 170, 1, };
static void *dev = &dev_info;
static unsigned long flags = 0x83;
int my_init(void)
{
	int ret;
	printk("my_init()\n");
	ret = request_irq(379, my_irq_handler,flags,"MY INT 1",dev);
	INIT_WORK(&dev_info.work, my_work_handler);
	return 0;
}

void my_exit(void)
{
	printk("my_exit()\n");
	free_irq(379, dev);
}

module_init( my_init );
module_exit( my_exit );
