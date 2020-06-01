#include <stdio.h>

#define MAX 100
#define INF 1000
#define NAR -1

int station[MAX];
int sCnt;
int minV;

int main(void) {
	int i, j;
	int tc;

	freopen("data.txt", "rt", stdin);
	scanf("%d", &tc);
	
	for(i=1; i<=tc ; i++){
		minV = INF;
		scanf("%d", &sCnt);
		
		for (j=0 ; j<sCnt ; j++) {
			scanf("%d", &station[j]);
		}

		dfs(0, 0, 0);
		if (minV == INF) {
			printf("TC%d : %d\n", i, NAR);
		}
		else {
			printf("TC%d : %d\n", i, minV);
		}
	}
	return 0;
}
/*--------------------------------------------------------------------------------------
Function Name : dfs() - ����ȸ���� ���̿켱Ž��(DFS) �ϴ� ����Լ� 
Argument      : n - Ž������
                energy - ���� �������� 
                c - ��������� ���� ȸ�� 
Return Valuse : ����
--------------------------------------------------------------------------------------*/
void dfs(int n, int energy, int c) {
	int i;

	// TODO

}


