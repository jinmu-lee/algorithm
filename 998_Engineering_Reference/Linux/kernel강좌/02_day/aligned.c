#include <stdio.h>

static char bar = 'a';
static int  foo 
__attribute__((aligned(1)))
= 0x77777777;

int main()
{
	printf("%p\n", &bar );
	printf("%p\n", &foo );
	return 0;
}
