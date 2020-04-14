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
#define RBUF_MAX 100

#define TEST_SEMAPHORE 1

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
			int arg = 12345678;

			if(strcmp(argv[2], "1") == 0) {
				printf("apptest: call ioctl() with MY_IOCTL_CMD_ONE\n");
				ret = ioctl(fd, MY_IOCTL_CMD_ONE);
				printf("apptest: return value is %d\n", ret);
			}
			else if(strcmp(argv[2], "2") == 0) {
				printf("apptest: call ioctl() with MY_IOCTL_CMD_TWO\n");
				ret = ioctl(fd, MY_IOCTL_CMD_TWO, &arg);
				printf("apptest: return value is %d\n", ret);
			}
			else {
				printf("apptest: call ioctl() with unknown command\n");
				ret = ioctl(fd, MY_IOCTL_CMD_THREE);
				printf("apptest: return value is %d (errno = %d)\n", ret, errno);
			}
		}
		else if(strcmp(argv[1], "L") == 0) {
			int ret;

			if(strcmp(argv[2], "ON") == 0) {
				printf("apptest: call ioctl() with MY_IOCTL_CMD_LED_ON\n");
				ret = ioctl(fd, MY_IOCTL_CMD_LED_ON);
				printf("apptest: return value is %d\n", ret);
			}
			else if(strcmp(argv[2], "OFF") == 0) {
				printf("apptest: call ioctl() with MY_IOCTL_CMD_LED_OFF\n");
				ret = ioctl(fd, MY_IOCTL_CMD_LED_OFF);
				printf("apptest: return value is %d\n", ret);
			}
			else {
				printf("apptest: call ioctl() with unknown command\n");
			}
		}
		else if(strcmp(argv[1], "Q") == 0) {
			int ret;

			if(strcmp(argv[2], "EN") == 0) {
				printf("apptest: call ioctl() with MY_IOCTL_CMD_IRQ_EN\n");
				ret = ioctl(fd, MY_IOCTL_CMD_IRQ_EN);
				printf("apptest: return value is %d\n", ret);
			}
			else if(strcmp(argv[2], "DIS") == 0) {
				printf("apptest: call ioctl() with MY_IOCTL_CMD_IRQ_DIS\n");
				ret = ioctl(fd, MY_IOCTL_CMD_IRQ_DIS);
				printf("apptest: return value is %d\n", ret);
			}
			else {
				printf("apptest: call ioctl() with unknown command\n");
			}
		}
#if TEST_SEMAPHORE
		else if(strcmp(argv[1], "S") == 0) {
			int sec = atoi(argv[2]);

			if((sec >= 1) && (sec <= 99)) {
				printf("apptest: sleeping for %d seconds\n", sec);
				sleep(sec);
			}
			else {
				printf("apptest: invalid range (use 1~99)\n");
			}
		}
#endif
	}

	close(fd);
	printf("apptest: %s closed\n", DEV_NAME);
	fflush(stdout);

	return 0;
}
