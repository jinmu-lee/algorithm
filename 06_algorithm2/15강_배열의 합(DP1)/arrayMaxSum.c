#include <stdio.h>
#define MAX 100      // ��� ���� �ִ� ��
int D[MAX+1][MAX+1];  // �������̺� �迭 
int A[MAX+1][MAX+1];  // �� ���� �� ���� �迭 
int row, col;         // ��, ���� ��
int f(int row, int col);
int main()
{
	int i,j;
	int tc, ti;
	freopen("data.txt", "rt", stdin);
	scanf("%d", &tc);
	printf("%d\n", tc);
	 
	for(ti=1; ti<=tc; ti++){
		scanf("%d %d", &row, &col);  /* ��� ���� �� �Է� */
		printf("%d %d \n", row, col);
		for(i=1; i<=row; i++){
			for(j=1; j<=col; j++){
				scanf("%d", &A[i][j]);
			}
		}
		// Dynamic Table �� ä���
	
		// TO DO

		printf("TC%d(DP) : %d\n", ti, D[row][col]);  // DP�� ���� �ذ�
		printf("TC%d(Re) : %d\n", ti, f(row,col));  // �Ϲ���� ȣ�� �ذ�

	}
	return 0;
}

int f(int row, int col)
{
	
	// TO DO

}



