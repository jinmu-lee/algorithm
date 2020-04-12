#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/vmalloc.h>

MODULE_LICENSE("GPL");

int my_init(void)
{
	char *p;
	printk("my_init()\n");
	p = vmalloc( 8*1024*1024 );
	p[0] = 'a';
	p[8*1024*1024-1] = 'z';
	printk("%c - %c\n", p[0], p[8*1024*1024-1] );
	vfree(p);

	return 0;
}

void my_exit(void)
{
	printk("my_exit()\n");
}

module_init( my_init );
module_exit( my_exit );
