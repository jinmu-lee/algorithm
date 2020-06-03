#include <stdio.h>
#define MAX 1000000

int queue[MAX + 1];
int visit[MAX + 1];
int front;
int rear;
int D[] = { -1, 1, 5, 10 };  //  이동 가능 거리 
void bfs(int me, int you);  //이동위치를 너비우선으로 탐색하는 함수 

int main(void) 
{
	int i;
	int tc;
	int start;
	int end;

	freopen("data.txt", "r", stdin);
	scanf("%d", &tc);
	for (i=1 ; i<=tc ; i++) {
		scanf("%d %d", &start, &end);
		bfs(start, end);
		printf("TC %d : %d\n", i, visit[end]);
	}
	return 0;
}
/*--------------------------------------------------------------------------------------
Function Name : bfs() - 이동위치를 너비우선으로 탐색하는 함수 
Argument      : me - 나의 위치 
                you - 그대의 위치 
Return Valuse : 없음
--------------------------------------------------------------------------------------*/
void bfs(int me, int you) {

	// TODO
	int count = 0;	
	for(int i=0;i<=MAX;i++) visit[i]=0;
	front=rear=0;
	queue[rear++] = me;
	visit[me] = count;	
	while(front!=rear){
		int c = queue[front++];
		if( c == you ) return;
		for(int i=0;i<4;i++){
			int n = c + D[i];
			if( n < 0 || n > MAX || n == me || visit[n] ) continue;
			visit[n] = visit[c] + 1;
			queue[rear++] = n;
		}
	}
}