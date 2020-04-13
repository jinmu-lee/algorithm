#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>
void **save_fp;
void **getFP(int dummy)
{
	void **fp = (void**)&dummy + 6 ;
	return fp;
}
void print_gnu_backtrace(void)
{
	int dummy=10;
	int frame = 0;
	Dl_info dlip;
	void **fp = getFP(dummy);
	void **ret = *(fp-1);
	save_fp = *(fp-3);
	while(save_fp)
	{
		if( dladdr(ret, &dlip) == 0 )
			break;
		printf("Frame %d : [fp=%p] [ret=%p] %s\n", frame++, save_fp, ret, dlip.dli_sname );
		fp = (void**)(save_fp);
		save_fp = *(fp-3);
		ret = *(fp-1);
	}
}


void bar()
{
	print_gnu_backtrace();
}

void foo()
{
	bar();
}

int main()
{
	foo();
	return 0;
}



