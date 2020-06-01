#include <stdio.h>
#define MAX 100      // 행과 열의 최대 수
int D[MAX+1][MAX+1];  // 동적테이블 배열 
int A[MAX+1][MAX+1];  // 각 방의 값 저장 배열 
int row, col;         // 행, 열의 수
int f(int row, int col);
int main()
{
	int i,j;
	int tc, ti;
	freopen("data.txt", "rt", stdin);
	scanf("%d", &tc);
	printf("%d\n", tc);
	 
	for(ti=1; ti<=tc; ti++){
		scanf("%d %d", &row, &col);  /* 행과 열의 수 입력 */
		printf("%d %d \n", row, col);
		for(i=1; i<=row; i++){
			for(j=1; j<=col; j++){
				scanf("%d", &A[i][j]);
			}
		}
		// Dynamic Table 값 채우기
	
		// TO DO

		printf("TC%d(DP) : %d\n", ti, D[row][col]);  // DP로 문제 해결
		printf("TC%d(Re) : %d\n", ti, f(row,col));  // 일반재귀 호출 해결

	}
	return 0;
}

int f(int row, int col)
{
	
	// TO DO

}



