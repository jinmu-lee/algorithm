#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define DEV_NAME "/dev/devtest"

int main(int argc, char *argv[])
{
	int fd;

	fd = open(DEV_NAME, O_RDWR);
	if(fd < 0) {
		printf("can't open %s\n", DEV_NAME);
		return -1;
	}
	printf("%s opened\n", DEV_NAME);
	sleep(1);

	close(fd);
	printf("%s closed\n", DEV_NAME);
	sleep(1);

	return 0;
}
