#if 1
#include <stdio.h>
int main()
{
	char a[] = "hello";
	char *q = "hello";
	*a = 'a'; 
	//a = "world"; // compile error
	printf("[%s]\n", a );
}


#endif
#if 0
#include <stdio.h>
int main()
{
	char *p = "hello";
	char *q = "hello";
	*p = 'a'; // runtime error
	p = "world";
}

#endif
#if 0
#include <stdio.h>
int main()
{
	int i;

	for( i=0; "hello"[i]; i++ )
		putchar(i["hello"]);
	putchar('\n');
	return 0;
}
#endif
#if 0
#include <stdio.h>
int main()
{
	char *p = "hello";
	int i;

	for( ; p[i]; p++ )
		putchar(*(p+i));
	putchar('\n');
	return 0;
}
#endif
#if 0
#include <stdio.h>
int main()
{
	char *p = "hello";
	//printf("sizeof(p)=%lu, [%s]\n", sizeof p , p);
	//printf("sizeof(\"hello\")=%lu, [%s]\n", 
	//		sizeof "hello" , "hello");

	printf("%c\n", p[1]);
	printf("%c\n", *(p+1));
	printf("%c\n", "hello"[1]);
	printf("%c\n", *("hello"+1));
	printf("%c\n", 1["hello"]);
	printf("%c\n", *(1+"hello"));
	return 0;
}
#endif
