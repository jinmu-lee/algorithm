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

//This is a naive implementation, shown for comparison,
//and to help in understanding the better functions.
//This algorithm uses 24 arithmetic operations (shift, add, and).
int popcount(int x)
{
	x = (x & m1 ) + ((x >>  1) & m1 ); //put count of each  2 bits into those  2 bits 
	x = (x & m2 ) + ((x >>  2) & m2 ); //put count of each  4 bits into those  4 bits 
	x = (x & m4 ) + ((x >>  4) & m4 ); //put count of each  8 bits into those  8 bits 
	x = (x & m8 ) + ((x >>  8) & m8 ); //put count of each 16 bits into those 16 bits 
	x = (x & m16) + ((x >> 16) & m16); //put count of each 32 bits into those 32 bits 
#if 0
	x = (x & m32) + ((x >> 32) & m32); //put count of each 64 bits into those 64 bits 
#endif
	return x;
}


int main(){
//	printf("%d\n",bit_count(0x12345678));
	printf("%d\n",popcount(0x12345678));

	return 0;
}
