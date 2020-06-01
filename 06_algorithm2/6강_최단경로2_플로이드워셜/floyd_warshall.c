#include<stdio.h>
#define MAX 100   // �ִ� ��� ���� 
#define INF  1000  // ���� ����ġ 

int dist[MAX+1][MAX+1];  // �׷��� ���� ���� ����(���� ��Ĺ�)
int path[MAX+1][MAX+1];  // path ���� �迭 
int vertext,edge;     // ������ ������ ������ ���� ���� 
void initGraph();    // ������ ������ ������ ������ķ� �����ϴ� �Լ� 
void floydWarshall();  // floydWarshall �˰������� �ִܰŸ��� ��� ���ϴ� �Լ� 
void printPath(int s, int t);   // ��� ��� ����Լ�(���������� �� ������ ������ �߰����� ���)  
void printGraph(int (*p)[MAX+1]);  // ��������̳�  ��������(Predecessor) ���� �迭 ��� 

int main()
{
	int s, e;
	initGraph();
	printf("[Graph matrix]\n");
	printGraph(dist);
	
	floydWarshall();  // floydWarshall �˰��� ���� 
	 
	printf("[Predecessor]\n");
	printGraph(path);

	// ��� ���
	s = 1;   // ��� ���� 1 
	e = 6;   // ���� ���� 6 
	printf("%d->%d �̵� ��� : %d >", s, e, s);
	printPath(1,6);
	printf("%d\n", e);

	return 0;
}

/*--------------------------------------------------------------------------------------
Function Name : floydWarshall() - floydWarshall �˰������� �ִܰŸ��� ��� ���ϴ� �Լ� 
Argument      : ���� 
Return Valuse : ����
--------------------------------------------------------------------------------------*/
void floydWarshall()
{
	// TODO
}

/*--------------------------------------------------------------------------------------
Function Name : initGraph() - ������ ������ ������ ������ķ� �����ϴ� �Լ� 
Argument      : ���� 
Return Valuse : ����
--------------------------------------------------------------------------------------*/
void initGraph()
{
	// TODO	
}
/*--------------------------------------------------------------------------------------
Function Name : printGraph() - ��������̳�  ��������(Predecessor) ���� �迭 ��� 
Argument      : p - ����� �迭 
Return Valuse : ����
--------------------------------------------------------------------------------------*/
void printGraph(int (*p)[MAX+1])
{
	int i, j;
	
	for (i=1; i<=vertext; i++) {
		for (j=1; j<=vertext; j++) {
			printf("%5d", p[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}
/*--------------------------------------------------------------------------------------
Function Name : printPath() - ��� ��� ����Լ�(���������� �� ������ ������ �߰����� ���) 
Argument      : s, t  -  ���� ���� 
Return Valuse : ����
--------------------------------------------------------------------------------------*/
void printPath(int s, int t)
{
	// TODO
}
	

