#if 1
#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>


int (*fp)(int,int);
int main()
{
	int ret;
    void *handle;
	Dl_info info;
	handle = dlopen("libadd.so", RTLD_LAZY);
	fp = dlsym( handle, "add" );
    dladdr( fp, &info);
	ret = fp(1,2);
	printf("ret=%d\n", ret );
	printf("function name=%s\n", info.dli_sname );
	dlclose(handle);
}
#endif

#if 0
#include <stdio.h>
int add(int,int);
int main()
{
	int ret;
	ret = add(1,2);
	printf("ret=%d\n", ret );
}
#endif
