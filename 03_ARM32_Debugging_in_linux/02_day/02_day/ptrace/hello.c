#include <stdio.h>
#include <unistd.h>
int main()
{
	char a[] = "hello!";
	while(1)
	{
		printf("%s\n", a);
		sleep(1);
	}
}

