#if 1
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include <linux/string.h>

MODULE_LICENSE("GPL");

typedef struct my_struct
{
	int gpio;
	char name[196];
} __attribute__((packed)) DEV_INFO;

#define L1_CACHE_SHIFT		6
#define L1_CACHE_BYTES		(1 << L1_CACHE_SHIFT)
#define ARCH_MIN_TASKALIGN	L1_CACHE_BYTES
static struct kmem_cache *my_struct_cachep;
int my_init(void)
{
	DEV_INFO *dev_info;
	printk("my_init()\n");
	my_struct_cachep =
		        kmem_cache_create(
						"my_struct", 
						sizeof(DEV_INFO),
						1, 
						SLAB_PANIC | SLAB_NOTRACK, 
						NULL);
	dev_info=kmem_cache_alloc( my_struct_cachep, GFP_KERNEL );
	dev_info->gpio = 170;
	strcpy(dev_info->name, "my_gpio_dev");
	printk("gpio=%d , name=%s\n" , dev_info->gpio, dev_info->name );
	kmem_cache_free( my_struct_cachep, dev_info );
	return 0;
}

void my_exit(void)
{
	printk("my_exit()\n");
	kmem_cache_destroy(my_struct_cachep);
}

module_init( my_init );
module_exit( my_exit );
#endif
#if 0
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include <linux/string.h>

MODULE_LICENSE("GPL");

int my_init(void)
{
	struct task_struct *p;
	printk("my_init()\n");
	p = kmalloc(sizeof(struct task_struct), GFP_KERNEL);
	p->pid = 1234;
	strcpy(p->comm, "my_process");
	printk("pid=%d , comm=%s\n" , p->pid, p->comm );
	kfree( p );
	return 0;
}

void my_exit(void)
{
	printk("my_exit()\n");
}

module_init( my_init );
module_exit( my_exit );
#endif
#if 0
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

int my_init(void)
{
	char *p;
	printk("my_init()\n");
	p = (char*)kmalloc(64, GFP_KERNEL);
	p[0] = 'a';
	p[63] = 'z';
	printk("%c - %c\n" , p[0], p[63] );
	kfree( p );
	return 0;
}

void my_exit(void)
{
	printk("my_exit()\n");
}

module_init( my_init );
module_exit( my_exit );
#endif
