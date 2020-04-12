#include <unistd.h>
#include <sys/syscall.h>

int main()
{
	syscall(255);
	return 0;
}
