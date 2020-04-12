#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	int ret, fd;
	char buff[128];
	fd = open("aaa", O_RDONLY);
	ret = read(fd, buff, 2);
	write(1, buff, ret );  // he
	ret = read(fd, buff, 2);
	write(1, buff, ret );  // ll
	close(fd);
	return 0;
}

