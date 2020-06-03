#include <stdio.h>
#define MAX 100

typedef struct _coord { 
	int r;
	int c;
} coord_t;

int box[MAX][MAX];  // ������� ���� �迭 
int row;
int col;
coord_t queue[MAX * MAX];
int rear;
int front;
int dr[] = { 0, 1, 0, -1 };   
int dc[] = { 1, 0, -1, 0 };
int day;  // �� �ҿ��ϼ� ���� ���� 

void init(void);  // ���������ϳ��� ��������� �о ����
void bfs(void);   // ����� ������ �ʺ�켱���� Ž���ϴ� �Լ�
 
int main(void) {
	int i;
	int tc;

	freopen("data.txt", "rt", stdin);
	scanf("%d", &tc);
	for (i=1 ; i<=tc ; i++) {
		day = 0;
		row = col = 0;
		scanf("%d %d", &row, &col);
		init();
		bfs();

		printf("TC%d : %d\n", i, day - 1);
	}

	return 0;
}
/*--------------------------------------------------------------------------------------
Function Name : init() - ���������� ���� ��������� �о ����
Argument      : x, y - Ž���� ������ x, y ��ǥ 
Return Valuse : ����
--------------------------------------------------------------------------------------*/
void init(void) {
	int i;
	int j;
	
	for (i=0 ; i<row ; i++) {
		for (j=0 ; j<col ; j++) {
			scanf("%d ", &box[i][j]);
		}
	}
}
/*--------------------------------------------------------------------------------------
Function Name : bfs() - ����� ������ �ʺ�켱���� Ž���ϴ� �Լ� 
Argument      : ����
Return Valuse : ����
--------------------------------------------------------------------------------------*/
void bfs(void) {
	// TO DO
	front = rear = 0;
	coord_t c,n,v;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if( box[i][j] == 1 ){
				c.r = i; c.c = j;
				queue[rear++] = c;
			}
		}
	}
	while(front!=rear){
		n = queue[front++];
		if( box[n.r][n.c] > day ){
			day = box[n.r][n.c];
		}
		for(int i=0;i<4;i++){
			v.r = n.r + dr[i];
			v.c = n.c + dc[i];
			if( v.r < 0 || v.r >= row || v.c < 0 || v.c >= col ) continue;
			if( box[v.r][v.c] == 0 ){
				box[v.r][v.c] = box[n.r][n.c] + 1;
				queue[rear++] = v;
			}
		}
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if( box[i][j] == 0 ){
				day = 1;
			}
		}
	}
}
