#include <stdio.h>
int main()
{
	int a[5] = {1,2,3,4,5};
	int *p = &a[3];

	int idx;

	idx = p - a;
	printf("idx=%d\n", idx);
	return 0;
}
