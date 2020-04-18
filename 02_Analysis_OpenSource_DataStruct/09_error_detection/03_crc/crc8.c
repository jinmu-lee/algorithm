#include <stdio.h>

#define CRC8_TABLE_SIZE 256
typedef unsigned char u8;
u8 table[CRC8_TABLE_SIZE];
/*
 * crc8_populate_msb - fill crc table for given polynomial in reverse bit order.
 *
 * table:       table to be filled.
 * polynomial:  polynomial for which table is to be filled.
 */
void crc8_populate_msb(u8 *table, u8 polynomial)
{
        int i, j;
        const u8 msbit = 0x80;
        u8 t = msbit;
        table[0] = 0;
         for (i = 1; i < CRC8_TABLE_SIZE; i *= 2) {
                 t = (t << 1) ^ (t & msbit ? polynomial : 0);
                 for (j = 0; j < i; j++)
                         table[i+j] = table[j] ^ t;
         }
}

u8 crc8(u8 table[CRC8_TABLE_SIZE],u8 *pdata,size_t nbytes,u8 crc){
	while(nbytes--){
		crc = table[(crc^*pdata++) & 0xff];
	}
	return crc;
}
void display(u8 *table){
	int i;
	for(i=0;i<CRC8_TABLE_SIZE;i++){
		printf("%02x ",table[i]);
		if( (i+1)%16 == 0 ) printf("\n");
	}
}

int main(){
	u8 data[3] = {0x12,0x34,0x0};
	u8 crc = 0x0;
	crc8_populate_msb(table,0xd5);
	crc = crc8(table,data,2,0);
	printf("crc=%#x\n",crc);
	data[2] = crc;
	display(table);
	/*
	 	Error Generation
	data[0]++;
	data[1]--;
	*/
	//===========================================
	crc = crc8(table,data,3,0);
	if( crc == 0 )
		printf("correct data : %#x\n",crc);
	else
		printf("wrong data : %#x\n",crc);
	return 0;
}
