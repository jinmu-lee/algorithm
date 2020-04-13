#if 1
#include <stdio.h>
int main()
{
	unsigned char ch = 10;
	signed int num;
	num = ch;
	printf("%u\n", num );
	return 0;
}
#endif
#if 0
#include <stdio.h>
int main()
{
	signed int num = 10;
	//unsigned int num = 10;
	num <<= 1;
	printf("%d\n", num );
	return 0;
}
#endif
#if 0
#include <stdio.h>
int main()
{
	signed char ch = -10;
	ch >>= 1;
	printf("%d\n", ch );
	return 0;
}
#endif
#if 0
#include <stdio.h>
int main()
{
	//int num = 10;
	unsigned int num = 10;
	num >>= 1;
	printf("%d\n", num );
	return 0;
}
#endif
#if 0
#include <stdio.h>
int main()
{
	int num = 1;

	while(1)
	{
		printf("%d\n", num );
		num <<= 1;
		getchar();
	}
	return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int flag = 7;
	int key = flag^8;

	while(1)
	{
		printf("%d\n", flag );
		flag ^= key;
		getchar();
	}
	return 0;
}
#endif
#if 0
#include <stdio.h>
int main()
{
	int flag = 5;

	while(1)
	{
		printf("%d\n", flag );
		if(flag==5)
			flag = 6;
		else if( flag==6 )
			flag = 5;
		getchar();
	}
	return 0;
}
#endif
