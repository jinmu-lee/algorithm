#include <stdio.h>
#include <string.h>

int main(){
	char y[] = "how are you hellow world";
	char x[] = "hellow";
	char *p;
	p = strstr(y,x);
	printf("p=%s\n",p);
	return 0;
}
