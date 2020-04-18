#include <stdio.h>

int bit_count(int bitmap){
	int count=0;
	int i;
	for(i=0;i<32;i++){
		if(bitmap&(1<<i)){
			count++;
		}
	}
	return count;
}

int main(){
//	printf("%d\n",bit_count(0x12345678));
	printf("%d\n",popcount64a(m16));

	return 0;
}
