#include <stdio.h>
// # ./a.out   a      b       c
//   argv[0] argv[1] argv[2] argv[3]
// argc==4
int main( int argc, char **argv)
{
	int i;

	for(i=0; i<argc; i++ )
		printf("argv[%2d] : %s\n", i, argv[i] );

	return 0;
}
