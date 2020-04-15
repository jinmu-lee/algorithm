#include <stdio.h>
#include <stdlib.h>

struct flex{
	int count;
	int a[0];
};

int main(){
	int count = 100;
	struct flex *fa;
	fa = malloc(sizeof(struct flex)+sizeof(int)*count);
	fa->count = count;
	fa->a[0] = 1;
	fa->a[99] = 100;

	printf("sizeof(f)=%lu\n",sizeof((*fa)));
	printf("%p\n",fa);
	printf("%p\n",fa->a);
	printf("%p\n",fa->a+100);
	return 0;
}
