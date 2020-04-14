#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

pid_t pid;

int main(int argc, char **argv)
{
	pid_t pid_temp;	
	char *msg = "none";

	printf("[%d] running %s\n", pid = getpid(), argv[0]);

	pid_temp = fork();

	if(pid_temp == -1) {
		printf("[%d] error: %s (%d)\n", pid, strerror(errno), __LINE__);
		return EXIT_FAILURE;
	}
	else if(pid_temp == 0) {
		int ret;
		pid = getpid();
		msg = "this is child";
		printf("[%d] changing process to sleep\n", pid);
		ret = execlp("sleep", "sleep", "3", NULL);
		printf("[%d] ret = %#x\n", pid, ret);
	}
	else {
		pid_t pid_wait;
		int status;

		msg = "this is parent";
		printf("[%d] waiting child's termination\n", pid);
		pid_wait = wait(&status);
		printf("[%d] pid %d has been terminated with status %#x\n", pid, pid_wait, status);
	}

	printf("[%d] pid_temp = %d, msg = %s, ppid = %d\n", pid, pid_temp, msg, getppid());
	printf("[%d] terminted\n", pid);

	return EXIT_SUCCESS;
}

