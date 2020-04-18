#include <stdio.h>

typedef unsigned short __sum16;
typedef unsigned char __u8;
typedef unsigned short __be16;
typedef unsigned int __be32;

struct iphdr {
	__u8    ihl:4,
		version:4;
	__u8    tos;
	__be16  tot_len;
	__be16  id;
	__be16  frag_off;
	__u8    ttl;
	__u8    protocol;
	__sum16 check; // check-sum
	__be32  saddr;
	__be32  daddr;
	/*The options start here. */
};
static inline unsigned short from32to16(unsigned int x)
{
         /* add up 16-bit and 16-bit for 16+c bit */
         x = (x & 0xffff) + (x >> 16);
        /* add up carry.. */
         x = (x & 0xffff) + (x >> 16);
        return x;
}
static unsigned int do_csum(const unsigned char *buff, int len)
{
        int odd;
        unsigned int result = 0;

         if (len <= 0)
                 goto out;
         odd = 1 & (unsigned long) buff;
         if (odd) {

                 result += (*buff << 8);
                 len--;
                 buff++;
         }
         if (len >= 2) {
                 if (2 & (unsigned long) buff) {
                         result += *(unsigned short *) buff;
                         len -= 2;
                         buff += 2;
                 }
                 if (len >= 4) {
                         const unsigned char *end = buff + ((unsigned)len & ~3);
                         unsigned int carry = 0;
                         do {
                                 unsigned int w = *(unsigned int *) buff;
                                 buff += 4;
                                 result += carry;
                                 result += w;
                                 carry = (w > result);
                         } while (buff < end);
                         result += carry;
                         result = (result & 0xffff) + (result >> 16);
                 }
                 if (len & 2) {
                         result += *(unsigned short *) buff;
                         buff += 2;
                 }
         }
        if (len & 1)
                 result += *buff;
	         result = from32to16(result);
         if (odd)
                 result = ((result >> 8) & 0xff) | ((result & 0xff) << 8);
 out:
         return result;
}

__sum16 ip_fast_csum(const void *iph, unsigned int ihl)
{
         return (__sum16)~do_csum(iph, ihl*4);
}

int main(){
	unsigned short ip[] = {0x4510,0x00c8,0x244c,0x4000,0x4006,
			       0x0000,0xc0a8,0x3880,0xc0a8,0x3801};
	unsigned short sum = ip_fast_csum(ip,5);
	printf("%#x\n",sum);
	ip[5] = sum;
	// -------------------------------------------------------------
	// ip[5] |= 3; // make wrong data, able to check
	/*
	   // not able to check 
	   // 2 number of data changed
		ip[3]++;
		ip[4]--;
	*/
	 sum = ip_fast_csum(ip,5);
	if( sum == 0 ) 
		printf("correct data : %#x\n",sum);
	else
		printf("wrong data : %#x\n",sum);
	return 0;
}
