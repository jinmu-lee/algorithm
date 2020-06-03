#include <stdio.h>
#define MAX 1000000

int queue[MAX + 1];
int visit[MAX + 1];
int front;
int rear;
int D[] = { -1, 1, 5, 10 };  //  �̵� ���� �Ÿ� 
void bfs(int me, int you);  //�̵���ġ�� �ʺ�켱���� Ž���ϴ� �Լ� 

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
Function Name : bfs() - �̵���ġ�� �ʺ�켱���� Ž���ϴ� �Լ� 
Argument      : me - ���� ��ġ 
                you - �״��� ��ġ 
Return Valuse : ����
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