#include <stdio.h>
#define MAX 30

// d[n][0] n번째 자리가 0인 경우 d[n-1][1](앞자리가 1인 경우만 가능)
// d[n][1] n번째 자리가 1인 경우 d[n-1][0] + d[n-1][1](앞자리가 0, 1인 경우 모두 가능)

int main(void)
{
	int n;
	int d[MAX+1][2];
	int i;
	scanf("%d", &n);

	// TO DO

	return 0;
}
