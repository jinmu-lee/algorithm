#include <stdio.h>
#define MAX 100
int main(void)
{
	int N; // N개의 조
	int d[MAX+1][3] = {0, }; // d[i][j] : i조가 j색상을 골랐을 때 최소 합계 비용
	int w[MAX+1][3] = {0, }; // w[i][j] : i조가 j색상으로 인쇄할 때의 비용
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
