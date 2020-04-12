#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/mm_types.h>

MODULE_LICENSE("GPL");

typedef unsigned int kmem_bufctl_t;
struct slab {
	union {
		struct {
			struct list_head list;
			unsigned long colouroff;
			void *s_mem;		/* including colour offset */
			unsigned int inuse;	/* num of objs active in slab */
			kmem_bufctl_t free;
			unsigned short nodeid;
		};
	};
};

int my_init(void)
{
	printk("my_init()\n");
	printk("sizeof(page)=%lu\n", sizeof(struct page));
	printk("sizeof(slab)=%lu\n", sizeof(struct slab));
	return 0;
}

void my_exit(void)
{
	printk("my_exit()\n");
}

module_init( my_init );
module_exit( my_exit );
