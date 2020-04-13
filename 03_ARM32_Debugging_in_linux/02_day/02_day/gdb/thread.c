#if 1
#include <stdio.h>
#include <string.h>
#include <pthread.h>
void *foo(void *data)
{
	char ip[] = "192.168.137.100";
	char *p;
	char *saveptr;
	p = strtok_r(ip, ".", &saveptr);
	while(p)
	{
		printf("[%s]\n", p );
		p = strtok_r(saveptr, ".", &saveptr);
	}
	return 0;
}
void *bar(void *data)
{
	char hp[] = "010-1234-5678";
	char *p;
	char *saveptr;
	p = strtok_r(hp, "-", &saveptr);
	while(p)
	{
		printf("[%s]\n", p );
		p = strtok_r(saveptr, "-", &saveptr);
	}
	return 0;
}
int main()
{
	pthread_t thread[2];
	pthread_create(&thread[0], 0, foo, 0);
	pthread_create(&thread[1], 0, bar, 0);
	pthread_join(thread[0], 0);
	pthread_join(thread[1], 0);
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <string.h>
#include <pthread.h>
void *foo(void *data)
{
	char ip[] = "192.168.137.100";
	char *p;
	p = strtok( ip, "." );
	while(p)
	{
		printf("[%s]\n", p );
		p = strtok( 0, "." );
	}
	return 0;
}
void *bar(void *data)
{
	char hp[] = "010-1234-5678";
	char *p;
	p = strtok( hp, "-" );
	while(p)
	{
		printf("[%s]\n", p );
		p = strtok( 0, "-" );
	}
	return 0;
}
int main()
{
	pthread_t thread[2];
	pthread_create(&thread[0], 0, foo, 0);
	pthread_create(&thread[1], 0, bar, 0);
	pthread_join(thread[0], 0);
	pthread_join(thread[1], 0);
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <string.h>
#include <pthread.h>
void *foo(void *data)
{
	char ip[] = "192.168.137.100";
	char *p;
	p = strtok( ip, "." );
	while(p)
	{
		printf("[%s]\n", p );
		p = strtok( 0, "." );
	}
	return 0;
}
int main()
{
	pthread_t thread;
	pthread_create(&thread, 0, foo, 0);
	pthread_join(thread, 0);
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <string.h>
int main()
{
	char ip[] = "192.168.137.100";
	char *p;
	p = strtok( ip, "." );
	while(p)
	{
		printf("[%s]\n", p );
		p = strtok( 0, "." );
	}
	return 0;
}
#endif
