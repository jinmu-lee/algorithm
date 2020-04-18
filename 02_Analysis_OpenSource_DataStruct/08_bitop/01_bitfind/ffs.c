// ffs : find first set bit 
// 00000001 00000000 00000000 00000000

#include <stdio.h>

/**
 * __ffs - find first bit in word.
 * @word: The word to search
 *
 * Undefined if no bit exists, so code should check against 0 first.
 */
static __always_inline unsigned long __ffs(unsigned long word)
{
	int num = 0;

#if 1
	if ((word & 0xffffffff) == 0) {
		num += 32;
		word >>= 32;
	}
#endif
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

int my_ffs(int bitmap){
	// O(n)
	int i;
	for(i=0;i<32;i++){
		if( bitmap & (1<<i) ) break;
	}
	return i;
}
int main(){
//	printf("%d\n",my_ffs(0x01000000));
	printf("%ld\n",__ffs(0x1000000000000000));
	return 0;
}
