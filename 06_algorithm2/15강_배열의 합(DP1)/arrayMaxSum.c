#include <stdio.h>
#include <string.h>
#define MAX 100      // ��� ���� �ִ� ��
int D[MAX+1][MAX+1];  // �������̺� �迭 
int A[MAX+1][MAX+1];  // �� ���� �� ���� �迭 
int row, col;         // ��, ���� ��
int f(int row, int col);
inline int max(int a,int b){ return a>=b?a:b; }
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
		// TO DO
		memset(D,0,sizeof(D));
#if 0
		for(int i=1;i<=row;i++){
			for(int j=1;j<=col;j++){
				D[i][j] = max(D[i-1][j],D[i][j-1]) + A[i][j];
			}
		}
		printf("TC%d(DP) : %d\n", ti, D[row][col]);  // DP�� ���� �ذ�
#endif
		printf("TC%d(Re) : %d\n", ti, f(row,col));  // �Ϲ���� ȣ�� �ذ�

	}
	return 0;
}
int f(int row, int col)
{
	if( row == 0 || col == 0 ) return 0;
	int &ret = D[row][col];
	if( ret != 0 ) return ret;
	return ret = max(f(row-1,col),f(row,col-1)) + A[row][col];
}



