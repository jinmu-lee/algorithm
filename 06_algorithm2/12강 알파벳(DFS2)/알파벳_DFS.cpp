#include <stdio.h>
#define MAX 20
typedef enum { FALSE, TRUE } BOOL;

char board[MAX][MAX];  // 알파벳 저장 보드
int check[26];   // 방문한 알파벳 체크 배열

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int row, col;

int dfs(int x, int y); // 문자의 개수를 세기 위한 깊이우선탐색(DFS) 하는 재귀함수
int main() {

	int i, j;
	int tc, ti;
	freopen("data.txt", "rt", stdin);
	scanf("%d", &tc);
	
	// TODO

	return 0;
}
/*--------------------------------------------------------------------------------------
Function Name : dfs() - 문자의 개수를 세기 위한 깊이우선탐색(DFS) 하는 재귀함수
Argument      : x, y - 현재위치
Return Valuse : 지나온 문자의 개수 
--------------------------------------------------------------------------------------*/

int dfs(int x, int y) {

	// TODO
}



