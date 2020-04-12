#if 1

#define __PASTE(a,b)	a##b
#define PASTE(a,b)	__PASTE(a,b)

int PASTE(hello, __LINE__);
int PASTE(hello, __LINE__);

int main()
{
	return 0;
}
#endif

