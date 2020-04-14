#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#include "my_ioctl.h"

#define DEV_NAME "/dev/devtest"

int main(int argc, char *argv[])
{
	int fd, ret, read_val;

	fd = open(DEV_NAME, O_RDWR);
	if(fd < 0) {
		printf("apptest: can't open %s\n", DEV_NAME);
		return -1;
	}
	printf("apptest: %s opened\n", DEV_NAME);
	fflush(stdout);

	if(argc == 3) {
		if(strcmp(argv[1], "R") == 0) {
			ret = read(fd, &read_val, sizeof(int));
			if(ret == -1) {
				printf("apptest: can't read (errno = %d)\n", errno);
				return -1;
			}
			printf("apptest: ADC value is 0x%x\n", read_val);
			fflush(stdout);
			sleep(0.3);
		}
                else if(strcmp(argv[1], "C") == 0) {
                        int ret;
                        int arg = atoi(argv[2]);

			ret = ioctl(fd, MY_IOCTL_CMD_SET_MAX_COUNT, &arg);
                        printf("apptest: return value is %d\n", ret);
			fflush(stdout);
			sleep(0.3);
                }
	}

	close(fd);
	printf("apptest: %s closed\n", DEV_NAME);
	fflush(stdout);

	return 0;
}
