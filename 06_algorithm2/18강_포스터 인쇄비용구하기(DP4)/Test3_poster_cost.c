#include <stdio.h>
#define MAX 100
int main(void)
{
	int N; // N���� ��
	int d[MAX+1][3] = {0, }; // d[i][j] : i���� j������ ����� �� �ּ� �հ� ���
	int w[MAX+1][3] = {0, }; // w[i][j] : i���� j�������� �μ��� ���� ���
	int i;
	int minCost;
	int tc, ti;
	freopen("posterData.txt", "rt", stdin);
	scanf("%d", &tc);
	for(ti=1; ti<=tc; ti++){
		scanf("%d", &N);
		
		// TO DO

		printf("TC %d : %d\n", ti, minCost);
	}
	return 0;
}
