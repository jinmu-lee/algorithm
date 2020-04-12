#include <stdio.h>
void bar(void)
{
	printf("bar\n");
}
void foo(void) __attribute__((alias("bar")));
//------------------------------------

int main()
{
	foo();
}
