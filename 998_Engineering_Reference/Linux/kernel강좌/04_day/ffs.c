#include <stdio.h>
unsigned long __ffs(unsigned long word)
{
	int num = 0;

	if ((word & 0xffffffff) == 0) {
		num += 32;
		word >>= 32;
	}
	if ((word & 0xffff) == 0) {
		num += 16;
		word >>= 16;
	}
	if ((word & 0xff) == 0) {
		num += 8;
		word >>= 8;
	}
	if ((word & 0xf) == 0) {
		num += 4;
		word >>= 4;
	}
	if ((word & 0x3) == 0) {
		num += 2;
		word >>= 2;
	}
	if ((word & 0x1) == 0)
		num += 1;
	return num;
}

unsigned long my_ffs( unsigned long word )
{
	unsigned long i;
	for( i=0; i<64; ++i )
		if( word & (1UL<<i) )
			break;
	return i;
}

int main()
{
	unsigned long bitmap = 0;
	unsigned long idx;
	bitmap |= 1UL<<63;
	if( bitmap )
	{
		idx = __ffs(bitmap);
		printf("idx=%lu\n", idx );
	}
	else
		printf("세팅된 비트가 없습니다. \n");
	return 0;
}
