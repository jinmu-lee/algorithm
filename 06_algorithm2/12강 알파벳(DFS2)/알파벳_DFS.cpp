#include <stdio.h>
#define MAX 20
typedef enum { FALSE, TRUE } BOOL;

char board[MAX][MAX];  // ���ĺ� ���� ����
int check[26];   // �湮�� ���ĺ� üũ �迭

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int row, col;

int dfs(int x, int y); // ������ ������ ���� ���� ���̿켱Ž��(DFS) �ϴ� ����Լ�
int main() {

	int i, j;
	int tc, ti;
	freopen("data.txt", "rt", stdin);
	scanf("%d", &tc);
	
	// TODO

	return 0;
}
/*--------------------------------------------------------------------------------------
Function Name : dfs() - ������ ������ ���� ���� ���̿켱Ž��(DFS) �ϴ� ����Լ�
Argument      : x, y - ������ġ
Return Valuse : ������ ������ ���� 
--------------------------------------------------------------------------------------*/

int dfs(int x, int y) {

	// TODO
}



