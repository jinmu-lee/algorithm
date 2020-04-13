#if 1
#include <stdio.h>
#include <stdarg.h>
void bar()
{
}
int foo(int n, ...)    
{
	int i, num, result=0;
	va_list ap;    

	bar();
	va_start(ap, n);
	for (i = 0; i < n; i++)   
	{
		num = va_arg(ap, int);   
		result += num;
	}
	va_end(ap); 
	return result;
}

int main()
{
	int result;
	result = foo(2,10,20);
	printf("result=%d\n", result );
	return 0;
}
#endif
#if 0
int bar(int a, int b, int c, int d, int e, int f)
{
	int result;
	result = e+f;
	return result;
}

int foo(int a1, int a2)
{
	int result;
	result = a1+a2;
	bar(1,2,3,4,5,6);
	return result;
}

int main()
{
	int result;
	result = foo(10,20);
	return 0;
}
#endif
#if 0
void bar()
{
}

int foo(int a1, int a2)
{
	int result;
	result = a1+a2;
	bar();
	return result;
}

int main()
{
	int result;
	result = foo(10,20);
	return 0;
}
#endif
#if 0
int foo(int a1, int a2)
{
	int result;
	result = a1+a2;
	return result;
}

int main()
{
	int result;
	result = foo(10,20);
	return 0;
}
#endif
#if 0
void foo(void)
{
}

int main()
{
	foo();
	return 0;
}
#endif
