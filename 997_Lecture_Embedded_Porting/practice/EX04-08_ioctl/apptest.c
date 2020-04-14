#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#include "my_ioctl.h"

#define DEV_NAME "/dev/devtest"
#define RBUF_MAX 100

int main(int argc, char *argv[])
{
	int fd, len;
	char rbuf[RBUF_MAX];
	char *wbuf;
	int rlen, wlen;

	fd = open(DEV_NAME, O_RDWR);
	if(fd < 0) {
		printf("apptest: can't open %s\n", DEV_NAME);
		return -1;
	}
	printf("apptest: %s opened\n", DEV_NAME);
	fflush(stdout);

	if(argc == 3) {
		if(strcmp(argv[1], "R") == 0) {
			len = atoi(argv[2]);
			if(len > (RBUF_MAX-1)) {
				printf("apptest: read size is too big(can be read up to %d\n", RBUF_MAX-1);
				return -1;
			}

			rlen = read(fd, rbuf, len);
			if(rlen == -1) {
				printf("apptest: can't read\n");
				return -1;
			}
			rbuf[rlen] = 0;
			printf("apptest: %d bytes read [%s]\n", rlen, rbuf);
		} 
		else if(strcmp(argv[1], "W") == 0) {
			wbuf = argv[2];
			len = strlen(wbuf);

			wlen = write(fd, wbuf, len);
			if(wlen == -1) {
				printf("apptest: can't write\n");
				return -1;
			}
			wbuf[wlen] = 0;
			printf("apptest: %d bytes written [%s]\n", wlen, wbuf);
		}
		else if(strcmp(argv[1], "I") == 0) {
			int ret;
			int uarg = 12345678;

			if(strcmp(argv[2], "1") == 0) {
				printf("apptest: call ioctl() with MY_IOCTL_CMD_ONE\n");
				ret = ioctl(fd, MY_IOCTL_CMD_ONE);
				printf("apptest: return value is %d\n", ret);
			}
			else if(strcmp(argv[2], "2") == 0) {
				printf("apptest: call ioctl() with MY_IOCTL_CMD_TWO\n");
				ret = ioctl(fd, MY_IOCTL_CMD_TWO, &uarg);
				printf("apptest: return value is %d\n", ret);
			}
			else {
				printf("apptest: call ioctl() with unknown command\n");
				ret = ioctl(fd, MY_IOCTL_CMD_THREE);
				printf("apptest: return value is %d (errno = %d)\n", ret, errno);
			}
		}
	}

	close(fd);
	printf("apptest: %s closed\n", DEV_NAME);
	fflush(stdout);

	return 0;
}
