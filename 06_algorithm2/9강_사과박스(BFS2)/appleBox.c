#include <stdio.h>
#define MAX 100

typedef struct _coord { 
	int r;
	int c;
} coord_t;

int box[MAX][MAX];  // 사과정보 저장 배열 
int row;
int col;
coord_t queue[MAX * MAX];
int rear;
int front;
int dr[] = { 0, 1, 0, -1 };   
int dc[] = { 1, 0, -1, 0 };
int day;  // 총 소요일수 저장 변수 

void init(void);  // 데이터파일내의 사과정보를 읽어서 저장
void bfs(void);   // 사과의 정보를 너비우선으로 탐색하는 함수
 
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
Function Name : init() - 데이터파일 내의 사과정보를 읽어서 저장
Argument      : x, y - 탐색을 시작할 x, y 좌표 
Return Valuse : 없음
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
Function Name : bfs() - 사과의 정보를 너비우선으로 탐색하는 함수 
Argument      : 없음
Return Valuse : 없음
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
