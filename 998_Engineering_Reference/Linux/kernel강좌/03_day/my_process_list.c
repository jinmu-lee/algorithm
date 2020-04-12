#if 1
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");

int my_init(void)
{
	struct task_struct *p;
	printk("my_init()\n");

	for_each_process(p)
		printk("pid=%d, comm=%s\n", p->pid, p->comm );

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
#include <linux/sched.h>

MODULE_LICENSE("GPL");

int my_init(void)
{
	struct task_struct *p;
	struct list_head *temp;
	printk("my_init()\n");

	for( temp = init_task.tasks.next;
	     temp != &init_task.tasks;
	     temp = temp->next )
	{
		p = list_entry( temp, struct task_struct, tasks );
		printk("pid=%d, comm=%s\n", p->pid, p->comm );
	}

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
#include <linux/sched.h>

MODULE_LICENSE("GPL");

int my_init(void)
{
	struct task_struct *p;
	struct list_head *temp;
	printk("my_init()\n");
	for( temp = current->tasks.next;
			temp != &current->tasks;
			temp = temp->next )
	{
		p = list_entry( temp, struct task_struct, tasks );
		printk("pid=%6d, comm=%s\n", p->pid, p->comm );
	}

	p = list_entry( temp, struct task_struct, tasks );
	printk("pid=%6d, comm=%s\n", p->pid, p->comm );

	return 0;
}

void my_exit(void)
{
	printk("my_exit()\n");
}

module_init( my_init );
module_exit( my_exit );
#endif
