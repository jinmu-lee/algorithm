#include <stdio.h>

//O(logN)
//Reference from Wikipedia
//types and constants used in the functions below
//int is an unsigned 64-bit integer variable type (defined in C99 version of C language)
const int m1  = 0x55555555; //binary: 0101...
const int m2  = 0x33333333; //binary: 00110011..
const int m4  = 0x0f0f0f0f; //binary:  4 zeros,  4 ones ...
const int m8  = 0x00ff00ff; //binary:  8 zeros,  8 ones ...
const int m16 = 0x0000ffff; //binary: 16 zeros, 16 ones ...
#if 0
const int m32 = 0x00000000ffffffff; //binary: 32 zeros, 32 ones
#endif
const int h01 = 0x01010101; //the sum of 256 to the power of 0,1,2,3...


//This uses fewer arithmetic operations than any other known  
//implementation on machines with slow multiplication.
//This algorithm uses 17 arithmetic operations.
int popcountb(int x)
{
	x -= (x >> 1) & m1;             //put count of each 2 bits into those 2 bits
	x = (x & m2) + ((x >> 2) & m2); //put count of each 4 bits into those 4 bits 
	x = (x + (x >> 4)) & m4;        //put count of each 8 bits into those 8 bits 
	x += x >>  8;  //put count of each 16 bits into their lowest 8 bits
	x += x >> 16;  //put count of each 32 bits into their lowest 8 bits
#if 0
	x += x >> 32;  //put count of each 64 bits into their lowest 8 bits
#endif
	return x & 0x7f;
}

//This uses fewer arithmetic operations than any other known  
//implementation on machines with fast multiplication.
//This algorithm uses 12 arithmetic operations, one of which is a multiply.
int popcountc(int x)
{
	x -= (x >> 1) & m1;             //put count of each 2 bits into those 2 bits
	x = (x & m2) + ((x >> 2) & m2); //put count of each 4 bits into those 4 bits 
	x = (x + (x >> 4)) & m4;        //put count of each 8 bits into those 8 bits 
#if 0
	// 64Bit System
	return (x * h01) >> 56;  //returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24) + ... 
#else
	return (x * h01) >> 24;  //returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24) + ... 
#endif
}

// linux/lib/hweight.c
// kernel open source (equal to popcount c)
// unsigned int __sw_hweight32(unsigned int w)
int __sw_hweight32(int w)
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
	//printf("%d\n",popcountc(0x12345678));
	printf("%d\n",__sw_hweight32(0x12345678));
	return 0;
}
