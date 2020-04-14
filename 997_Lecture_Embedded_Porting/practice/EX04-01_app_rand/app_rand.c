#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_RAND_NUM 4

int main(void)
{
	int i, fd;
	char key[MAX_RAND_NUM];

	fd = open("/dev/urandom", O_RDONLY);

	if(fd == -1) {
		perror("open error");
	}

	if(read(fd, key, MAX_RAND_NUM) == -1) {
		perror("read error");
	}

	close(fd);

	for(i=0; i<MAX_RAND_NUM; i++) printf("%02X\n", key[i]);

	return 0;
}
