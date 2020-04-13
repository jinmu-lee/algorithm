#include <stdio.h>
void **getFP(int dummy)
{
	void **fp = (void**)&dummy + 6 ;
	void **temp;
	temp = __builtin_frame_address(0);
	printf("temp=%p\n", temp );
	return fp;
}

int main()
{
	void **fp = getFP(10);
	printf("  fp=%p\n", fp );
	return 0;
}
