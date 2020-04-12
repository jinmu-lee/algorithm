#include <stdio.h>

//#define container_of(ptr,type,member) \
//	(type *)((char *)ptr - (unsigned long)&((type *)0)->member)

#define offsetof(TYPE,MEMBER) ((size_t)&((TYPE *)0)->MEMBER)
#define container_of(ptr,type,member) ({\
		const typeof(((type *)0)->member) *__mptr = (ptr); \
		(type *)((char *)__mptr - offsetof(type,member));})

typedef struct{
	int a,b,c;
}AAA;

int main(){
	AAA aaa = {1,2,3};
	int *temp = &aaa.c;
//	AAA *p = (AAA *)((char *)temp - (unsigned long)&((AAA *)(0))->c);
	AAA *p = container_of(temp,AAA,c);
	printf("%d %d %d\n",p->a,p->b,p->c);
	return 0;
}
