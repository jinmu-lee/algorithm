#include <sys/ptrace.h>
#include <sys/user.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <asm/ptrace.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	struct user_regs regs;
	unsigned int data;
	unsigned char data2[4];
	int ret, pid, i, j;

	pid = atoi(argv[1]);

	ret = ptrace(PTRACE_ATTACH, pid, 0, 0);
	printf("return : %d\n", ret);
	ptrace(PTRACE_GETREGS, pid, 0, &regs);
	printf("stack = %p\n", (void*)regs.ARM_sp);
	for(i=0; i<300; i++)
	{
		data = ptrace(PTRACE_PEEKDATA, pid, regs.ARM_sp+i*4, 0);
		memcpy( data2, &data, 4 );
		printf("%08x : ", regs.ARM_sp+i*4);
		printf("%08x ", data);
		for(j=0; j<4; j++)
		{
			if( isprint(data2[j]) )
				printf("%c ", data2[j]);
			else
				printf(". ");
		}
		printf("\n");
	}
	ptrace(PTRACE_POKEDATA, pid, 0x7ea267c0, 0x41414141);
	ptrace(PTRACE_DETACH, pid, 0, 0);
}

