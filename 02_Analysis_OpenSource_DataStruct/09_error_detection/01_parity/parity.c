#include <stdio.h>

// linux/lib/hweight.c
// kernel open source (equal to popcount c)
// unsigned int __sw_hweight32(unsigned int w)
int hweight(int w)
{
#ifdef CONFIG_ARCH_HAS_FAST_MULTIPLIER
	w -= (w >> 1) & 0x55555555;
	w =  (w & 0x33333333) + ((w >> 2) & 0x33333333);
	w =  (w + (w >> 4)) & 0x0f0f0f0f;
	return (w * 0x01010101) >> 24;
#else
	unsigned int res = w - ((w >> 1) & 0x55555555);
	res = (res & 0x33333333) + ((res >> 2) & 0x33333333);
	res = (res + (res >> 4)) & 0x0F0F0F0F;
	res = res + (res >> 8);
	return (res + (res >> 16)) & 0x000000FF;
#endif
}

int main(){
	// Parity gurantees only odd count bit
	char data = 'a';
	if(hweight(data)%2){
		data |= 0x80; // Add parity bit
	}
	if(hweight(data)%2==0){
		printf("correct data\n");
	}else{
		printf("wrong data\n");
	}
	return 0;
}
