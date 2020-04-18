#include <stdio.h>

//This is better when most bits in x are 0
//This is algorithm works the same for all data sizes.
//This algorithm uses 3 arithmetic operations and 1 comparison/branch per "1" bit in x.
#if 0
int popcount64d(uint64_t x)
#endif
int popcountd(int x)
{
	int count;
	for (count=0; x; count++)
		x &= x - 1;
	return count;
}

int main(){
	printf("%d\n",popcountd(0x12345678));
	return 0;
}
