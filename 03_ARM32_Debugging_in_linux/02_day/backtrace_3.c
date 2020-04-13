#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
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
	void **fp = getFP(dummy);
	void **ret = *(fp-1);
	save_fp = *(fp-3);
	while(save_fp)
	{
		printf("%p\n", ret );
		fp = (void**)(save_fp);
		ret = *(fp-1);
		save_fp = *(fp-3);
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



