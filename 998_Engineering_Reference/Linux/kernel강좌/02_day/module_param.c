#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");

static int myint = 420;

// module_param( myint, int, 0644 );  // sysfs
module_param_named( myint_value, myint, int, 0644 );  

//static char *mystring="hello";
//module_param( mystring, charp, 0644);

static char buffer[128];
module_param_string( mystring, buffer, sizeof buffer, 0644);

static int myarray[2] = {-1, -1};
static int count;
module_param_array( myarray, int , &count, 0644);
int my_init(void)
{
	int i;
	printk("my_init()\n");
	printk("myint=%d\n", myint);
	printk("mystring=%s\n", buffer);
	printk("count=%d\n", count);
	for( i=0; i<count; i++ )
		printk("myarray[%d]=%d\n", i, myarray[i]);
	return 0;
}

void my_exit(void)
{
	printk("my_exit()\n");
}

module_init( my_init );
module_exit( my_exit );
