#include <stdio.h>
#define MAX 100
const int INF = 1000; // 무한대를 의미하는 가중치
int N;  // 정점(도시)의 개수
int M;  // 간선(버스노선) 개수
int cost[MAX+1][MAX+1];  // 최소 비용 저장 배열 
void initCost(const char *filename);  // 데이터파일내의 비용을 읽어서 인접행렬 형태로 저장하는 함수 
void floydWarshall();  // floydWarshall 알고리즘으로 최소비용을 구하는 함수 
void printCost();  // 최소비용배열(인접행렬)을 출력하는 함수 

int main() 
{
	int i;
	const char * fileList[] = {"floyd_bus1.txt", "floyd_bus2.txt", "floyd_bus3.txt"};
	for(i=0; i<sizeof(fileList)/sizeof(fileList[0]); i++){
		initCost(fileList[i]);
		floydWarshall();
		printf("(TC%d)\n", i);
		printCost();  // 계산된 요금 출력
	}
	return 0;
}
/*--------------------------------------------------------------------------------------
Function Name : initCost() - 데이터파일내의 비용을 읽어서 인접행렬 형태로 저장하는 함수 
Argument      : filename - 데이터 파일명 
Return Valuse : 없음
--------------------------------------------------------------------------------------*/
void initCost(const char *filename)
{
	// TODO
	freopen(filename,"r",stdin);
	scanf("%d %d",&N,&M);
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			if( i == j ) cost[i][j] = 0;
			else cost[i][j] = INF;
		}
	}
	for(int i=0;i<M;i++){
		int u,v,w; scanf("%d %d %d",&u,&v,&w);
		if( cost[u][v] > w ) // if 걸어줘야함, 필수임
			cost[u][v] = w;
	}

}
/*--------------------------------------------------------------------------------------
Function Name : floydWarshall() - floydWarshall 알고리즘으로 최소비용을 구하는 함수 
Argument      : 없음 
Return Valuse : 없음
--------------------------------------------------------------------------------------*/
void floydWarshall()
{
	// TODO
	for(int k=1;k<=N;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if( cost[i][j] > cost[i][k] + cost[k][j] ){
					cost[i][j] = cost[i][k] + cost[k][j];
				}
			}
		}
	}
}
/*--------------------------------------------------------------------------------------
Function Name : printCost() - 최소비용배열(인접행렬)을 출력하는 함수 
Argument      : 없음 
Return Valuse : 없음
--------------------------------------------------------------------------------------*/
void printCost()
{
	int i, j;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++)
			printf("%5d ", cost[i][j]);
		printf("\n");
	}
	printf("\n");
}
