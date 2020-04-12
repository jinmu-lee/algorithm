#if 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	pid_t pid;
	int fd1, fd2, ret;
	char buff[1024];
	fd1 = open("aaa", O_RDONLY );
	fd2 = open("aaa", O_RDONLY );
	ret = read( fd1, buff, 2 );
	write( 1, buff, ret );
	ret = read( fd2, buff, sizeof buff );
	write( 1, buff, ret );
	close(fd1);
	close(fd2);
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	pid_t pid;
	int fd1, fd2, ret;
	char buff[1024];
	fd1 = open("aaa", O_RDONLY );
	fd2 = dup(fd1);
	ret = read( fd1, buff, 2 );
	write( 1, buff, ret );
	ret = read( fd2, buff, sizeof buff );
	write( 1, buff, ret );
	close(fd1);
	close(fd2);
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	pid_t pid;
	int fd, ret;
	char buff[1024];
	fd = open("aaa", O_RDONLY );
	pid = fork();
	ret = read( fd, buff, 2 );
	write( 1, buff, ret );
	if( pid == 0 )
	{
		ret = read( fd, buff, sizeof buff );
		write( 1, buff, ret );
		exit(0);
	}
	close(fd);
	return 0;
}
#endif
