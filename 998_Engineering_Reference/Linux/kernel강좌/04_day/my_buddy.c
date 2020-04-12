#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/gfp.h>

MODULE_LICENSE("GPL");

int my_init(void)
{
	char *p;
	printk("my_init()\n");
	p = (char*)__get_free_pages( GFP_KERNEL, 0 );
	p[0] = 'a';
	p[4095] = 'z';
	printk("%c - %c\n", p[0], p[4095] );
	free_pages( (unsigned long)p, 0 );
	return 0;
}

void my_exit(void)
{
	printk("my_exit()\n");
}

module_init( my_init );
module_exit( my_exit );
