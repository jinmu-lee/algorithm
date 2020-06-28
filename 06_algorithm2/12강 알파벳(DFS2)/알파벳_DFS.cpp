#include <stdio.h>
#define MAX 20
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
	while(tc--){
		scanf("%d %d",&row,&col);		
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				scanf(" %c",&board[i][j]);
			}
		}
		for(i=0;i<26;i++) check[i] = 0;
#if 1
		check[board[0][0]-'A']=1;
		printf("%d\n",dfs(0,0));
#else
		int mxx=-1e9;
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				int count=dfs(i,j);
				if( count > mxx ) mxx = count;
				for(int k=0;k<26;k++) check[k]=0;
			}
		}
		printf("%d\n",mxx);
#endif
	}

	return 0;
}
/*--------------------------------------------------------------------------------------
Function Name : dfs() - ������ ������ ���� ���� ���̿켱Ž��(DFS) �ϴ� ����Լ�
Argument      : x, y - ������ġ
Return Valuse : ������ ������ ���� 
--------------------------------------------------------------------------------------*/
#if 1
int dfs(int x, int y) {
	// TODO
	int count = 0;	
	for(int i=0;i<4;i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if( nx < 0 || nx >= row || ny < 0 || ny >= col ) continue;
		if( check[board[nx][ny]-'A'] == 1 ) continue;
		check[board[nx][ny]-'A'] = 1;
		int next = dfs(nx,ny);
		if( count < next ) count = next;
		check[board[nx][ny]-'A'] = 0;
	}
	return count+1;
}
#else

int dfs(int x,int y){
	// TODO
	int count = 1;
	check[board[x][y]-'A'] = 1;
	for(int i=0;i<4;i++){
		int nx = x + dx[i];
		int ny = y + dy[i];		
		if( nx < 0 || nx >= row || ny < 0 || ny >= col ) continue;
		if( check[board[nx][ny]-'A'] == 1 ) continue;
		 count += dfs(nx,ny);
	}
	return count;	
}

#endif
