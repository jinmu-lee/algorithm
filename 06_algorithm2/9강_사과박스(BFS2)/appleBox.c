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
}
