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
}
/*--------------------------------------------------------------------------------------
Function Name : floydWarshall() - floydWarshall 알고리즘으로 최소비용을 구하는 함수 
Argument      : 없음 
Return Valuse : 없음
--------------------------------------------------------------------------------------*/
void floydWarshall()
{
	// TODO
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
