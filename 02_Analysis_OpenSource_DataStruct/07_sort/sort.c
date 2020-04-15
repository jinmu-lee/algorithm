#include <stdio.h>
#include <stdlib.h>

void generic_swap(void *a,void *b,int size){
	while(size--){
		char t=*(char *)a;
		*(char *)a++=*(char *)b;
		*(char *)b++=t;
	}
}
int compare(const void *a,const void *b){
	return (*(int *)a)-(*(int *)b) > 0;
}
void bubble(void *a,int n,int size,int (*cmp)(const void*,const void*)){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if( cmp((char*)a+j*size,(char *)a+(j+1)*size) > 0 )
				generic_swap((char *)a+j*size,(char *)a+(j+1)*size,size);
		}
	}
}
int main(){
	int a[] = {4,3,5,2,6,1,7};
	int i;
//	bubble(a,7,sizeof(int),compare);
	qsort(a,7,sizeof(int),compare);
	for(i=0;i<7;i++){
		printf("%4d",a[i]);
	}
	printf("\n");
	return 0;
}
