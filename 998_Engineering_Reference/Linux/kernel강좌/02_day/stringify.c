#if 1

#define __stringify_1(x...)	#x
#define __stringify(x...)	__stringify_1(x)

__stringify(__LINE__);  // #__LINE__ => "__LINE__"

int main()
{
	return 0;
}
#endif

#if 0
#define foo bar

#define __stringify_1(x...)	#x
#define __stringify(x...)	__stringify_1(x)

__stringify(foo);  // #foo => "foo"

int main()
{
	return 0;
}
#endif
