#include <stdio.h>

void foo(void)
{
	int i;
	for(i=0; i<5; i++)
		printf("hello ubuntu\n");
}
int main()
{
	foo();
	return 0;
}
