#include <stdio.h>
#define MAX 30

// d[n][0] n��° �ڸ��� 0�� ��� d[n-1][1](���ڸ��� 1�� ��츸 ����)
// d[n][1] n��° �ڸ��� 1�� ��� d[n-1][0] + d[n-1][1](���ڸ��� 0, 1�� ��� ��� ����)

int main(void)
{
	int n;
	int d[MAX+1][2];
	int i;
	scanf("%d", &n);

	// TO DO

	return 0;
}
