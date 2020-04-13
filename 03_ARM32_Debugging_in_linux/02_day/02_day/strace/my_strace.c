#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <asm/ptrace.h>

int main(int argc, char *argv[])
{
	int pid, status, ret;
	struct user_regs regs;
	unsigned int data;
	char *p;
	if(!(pid = fork())) {
		ptrace(PTRACE_TRACEME, 0, 0, 0);
		execlp( "ls" , "ls" , NULL );
		return 0;
	}

	while(1)
	{
		waitpid(pid, &status, 0);
		ptrace(PTRACE_GETREGS, pid, 0, &regs);

		if(WSTOPSIG(status) == SIGTRAP)
		{
			if( regs.ARM_r7 == 5 )
			{
				if( regs.ARM_ip == 0 )
				{
					fprintf(stderr, "open(\"");
					data = ptrace(PTRACE_PEEKDATA, pid, regs.ARM_r0, 0);
					p = (char*)&data;
					fprintf(stderr, "%c%c%c%c\", ...)", 
							p[0], p[1], p[2], p[3]);
				}
				else
				{
					fprintf(stderr, "=%d\n", regs.ARM_r0);
				}
			}
		}

		// continue debugee process
		ptrace(PTRACE_SYSCALL, pid, 0, 0);
	}
}

