#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
int global=10;
int bss;
int main()
{
	int i;
	int *p;
	void *handle;
	int (*fp)(int,int);
	handle = dlopen("libadd.so", RTLD_NOW);
	fp = dlsym(handle, "add");
	p = malloc(sizeof(int));
	printf("main=%p\n", main );
	printf("global=%p\n", &global );
	printf("bss=%p\n", &bss );
	printf("p=%p\n", p );
	printf("add=%p\n", fp);
	printf("i=%p\n", &i );
	printf("add(1,2)=%d\n", fp(1,2));
	dlclose(handle);
	return 0;
}
