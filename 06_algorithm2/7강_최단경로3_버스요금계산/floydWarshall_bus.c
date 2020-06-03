#include <stdio.h>
#define MAX 100
const int INF = 1000; // ���Ѵ븦 �ǹ��ϴ� ����ġ
int N;  // ����(����)�� ����
int M;  // ����(�����뼱) ����
int cost[MAX+1][MAX+1];  // �ּ� ��� ���� �迭 
void initCost(const char *filename);  // ���������ϳ��� ����� �о ������� ���·� �����ϴ� �Լ� 
void floydWarshall();  // floydWarshall �˰������� �ּҺ���� ���ϴ� �Լ� 
void printCost();  // �ּҺ��迭(�������)�� ����ϴ� �Լ� 

int main() 
{
	int i;
	const char * fileList[] = {"floyd_bus1.txt", "floyd_bus2.txt", "floyd_bus3.txt"};
	for(i=0; i<sizeof(fileList)/sizeof(fileList[0]); i++){
		initCost(fileList[i]);
		floydWarshall();
		printf("(TC%d)\n", i);
		printCost();  // ���� ��� ���
	}
	return 0;
}
/*--------------------------------------------------------------------------------------
Function Name : initCost() - ���������ϳ��� ����� �о ������� ���·� �����ϴ� �Լ� 
Argument      : filename - ������ ���ϸ� 
Return Valuse : ����
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
		if( cost[u][v] > w ) // if �ɾ������, �ʼ���
			cost[u][v] = w;
	}

}
/*--------------------------------------------------------------------------------------
Function Name : floydWarshall() - floydWarshall �˰������� �ּҺ���� ���ϴ� �Լ� 
Argument      : ���� 
Return Valuse : ����
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
Function Name : printCost() - �ּҺ��迭(�������)�� ����ϴ� �Լ� 
Argument      : ���� 
Return Valuse : ����
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
