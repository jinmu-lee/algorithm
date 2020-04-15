#include <stdio.h>

void generic_swap(void *a,void *b,int size){
	while(size--){
		char t=*(char *)a;
		*(char *)a++=*(char *)b;
		*(char *)b++=t;
	}
}
int main(){
	int a=3,b=4;
	generic_swap(&a,&b,sizeof(a));
	printf("a=%d, b=%d\n",a,b);
	return 0;
}
