#if 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int status;
	int i;
	if(0==fork())
	{
		for(i=0;;i++)
		{
			sleep(1);
			printf("child : %d\n", i );
		}
		exit(7);
	}
	while(1)
	{
		waitpid( -1,&status, WUNTRACED|WCONTINUED  );
		printf("status = %x\n", status );
		if( WIFEXITED(status) )  // (status & 0x7f) == 0
		{
			printf("exit(%d)\n", WEXITSTATUS(status) );
			break;
		}
		else if( WIFSIGNALED(status) )
		{
			printf("signo=%d %s\n", WTERMSIG(status),
					WCOREDUMP(status)?",(core dumped)":"" );
			break;
		}
		else if( WIFSTOPPED(status) )
			printf("stop(%d)\n", WSTOPSIG(status) );
		else if( WIFCONTINUED(status) )
			printf("continue\n");
	}
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int status;
	if(0==fork())
	{
		while(1)
			;
		exit(7);
	}
	wait( &status );
	if( status&0xff )
		printf("signo=%d\n", status&0xff );
	else
		printf("exit(%d)\n", (status>>8)&0xff );
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int status;
	if(0==fork())
	{
		sleep(1);
		exit(7);
	}
	wait( &status );
	printf("status=%d\n", (status>>8)&0xff );
	return 0;
}
#endif

