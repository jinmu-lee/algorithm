#include <stdio.h>
#include "Dijkstra.h"

int G[MAX][MAX];	/* �׷��� �迭 */
int V[MAX];			/* ��� ó�� üũ �迭 */
int D[MAX];			/* �ִܰŸ� ���� �迭 */
int P[MAX];			/* ������� ���� �迭 */
int vertex;			/* ���� �� ���� �迭 */
int edge;			/* ���� �� ���� �迭 */
/*--------------------------------------------------------------------------------------
Function Name : dijkstra() - ���޵� �������� ���� ������ ���������� �ּ� ����ġ�� ����ϰ� 
                             ��θ� ������
Argument      : s - ���õ� ���� ��ȣ
Return Valuse : ����
--------------------------------------------------------------------------------------*/
void dijkstra(int s) 
{
	/* distance�� predecessor, visited �迭 �ʱ�ȭ */
	int i;
	int j;

	// TODO
}
/*--------------------------------------------------------------------------------------
Function Name : printPredecessor() - �������� ���� �迭 ��� �Լ� 
Argument      : ���� 
Return Valuse : ����
--------------------------------------------------------------------------------------*/
void printPredecessor(void) 
{
	int i;

	printf("[Predecessor]\n"); 
	for (i=0 ; i<vertex ; i++) {
		printf("%2c ", i + 'A');
	}
	printf("\n");

	for (i=0 ; i<vertex ; i++) {
		printf("%2c ", P[i] + 'A');
	}
	printf("\n");
}

/*--------------------------------------------------------------------------------------
Function Name : printPath() - ���� ����->�� ���������� path �� ����ġ ���
Argument      : s - ���� ���� ��ȣ
			    t- ���� ���� ��ȣ
Return Valuse : ����
--------------------------------------------------------------------------------------*/
void printPath(int s, int t) 
{
	// TODO
}
/*--------------------------------------------------------------------------------------
Function Name : printDistance() - ������������ ���� �� ���������� �ּҰ���ġ�� 
                                �����ϰ� �ִ� �迭 ��� �Լ� 
Argument      : s - ���õ� ���� ��ȣ
Return Valuse : ����
--------------------------------------------------------------------------------------*/

void printDistance(int s) 
{
	int i;
	printf("[Distance]\n"); 
	printf("%c > ", s + 'A');
	for (i=0 ; i<vertex ; i++) {
		printf("%2c", i + 'A');
	}
	printf("\n");

	printf("    ");
	for (i=0 ; i<vertex ; i++) {
		if (D[i] == INF) {
			printf("%2c", 'x');
		}
		else {
			printf("%2d", D[i]);
		}
	}
	printf("\n");
}
/*--------------------------------------------------------------------------------------
Function Name : initGraph() - �׷��� �����͸� �о�鿩 �����࿭ ���� 
Argument      : ���� 
Return Valuse : ����
--------------------------------------------------------------------------------------*/
void initGraph(void) 
{
	int i, j;

	// TODO

}
/*--------------------------------------------------------------------------------------
Function Name : printGraph() - �׷��� �����࿭ ��� 
Argument      : ���� 
Return Valuse : ����
--------------------------------------------------------------------------------------*/
void printGraph(void) 
{
	int i;
	int j;
	printf("[Print Graph]\n"); 
	printf("%3s", "");
	for (i=0 ; i<vertex ; i++) {
		printf("%3c", 'A' + i);
	}
	printf("\n");

	for (i=0 ; i<vertex ; i++) {
		printf("%3c", 'A' + i);
		for (j=0 ; j<vertex ; j++) {
			if (G[i][j] == INF) {
				printf("%3s", "��");
			}
			else {
				printf("%3d", G[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}


