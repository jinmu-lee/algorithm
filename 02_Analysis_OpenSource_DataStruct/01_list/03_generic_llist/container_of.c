#include <stdio.h>

typedef struct{
	int a,b,c;
}AAA;

int main(){
	AAA aaa = {1,2,3};
	int *temp = &aaa.c;
	AAA *p = (AAA *)((char *)temp - (unsigned long)&((AAA *)(0))->c);
	printf("%d %d %d\n",p->a,p->b,p->c);
	return 0;
}
