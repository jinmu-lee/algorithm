#if 1
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
	int fd;
	int i=0;
	fd = open("main.c",  O_RDONLY );
	printf("after\n");

	return 0;
}
#endif
#if 0
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void err_quit( char *msg )
{
	perror(msg);
	exit(-1);
}
int Open(const char *pathname, int flags)
{
	int fd;
	fd = open(pathname,  flags );
	if( fd < 0 )
		err_quit("open()");
	return fd;
}

int main()
{
	int fd;
	int i=0;
	fd = Open("/tmp/foo",  O_RDONLY );
	printf("after\n");

	return 0;
}
#endif
#if 0
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void err_quit( char *msg )
{
	perror(msg);
	exit(-1);
}
int main()
{
	int fd;
	int i=0;
	fd = open("/tmp/foo",  O_RDONLY );
	if( fd < 0 )
		err_quit("open()");
	printf("after\n");

	return 0;
}
#endif
#if 0
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
int main()
{
	int fd;
	int i=0;
	fd = open("/tmp/foo",  O_RDONLY );
	if( fd < 0 )
	{
		perror("open()");
		exit(-1);
	}
	printf("after\n");

	return 0;
}
#endif
#if 0
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main()
{
	int fd;
	int i=0;
	fd = open("/tmp/foo",  O_RDONLY );
	printf("fd=%d\n", fd );
	if( fd < 0 )
		printf("open() : %s\n", strerror(errno));

	return 0;
}
#endif

