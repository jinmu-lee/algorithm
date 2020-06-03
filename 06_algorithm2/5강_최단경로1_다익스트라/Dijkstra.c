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
	// �ʱ�ȭ
	for (i = 0; i < vertex; i++) {
		D[i] = G[s][i];
		V[i] = 0;
		if (G[s][i] != INF) P[i] = s;
		else P[i] = NIL;
	}	
	V[s] = 1;

	// beginning of dijkstra
	for (i = 0; i < vertex; i++) {
		// ���� ���� �˻�
		// pq �� �����̶�� �����ϸ� ��
		int minidx = 0;
		int minval = INF;
		for (j = 0; j < vertex; j++) {
			if ((V[j] == 0) && (D[j] < minval)) {
				minidx = j;
				minval = D[j];
			}
		}
		V[minidx] = 1;

		// dijkstra
		for (j = 0; j < vertex; j++) {
			if (V[j] == 0) { // �������� �κ�
				if (D[minidx] + G[minidx][j] < D[j]) {
					D[j] = D[minidx] + G[minidx][j];
					P[j] = minidx;
				}
			}
		}
	}
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
	for (i = 0; i<vertex; i++) {
		printf("%2c ", i + 'A');
	}
	printf("\n");

	for (i = 0; i<vertex; i++) {
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
	int stack[MAX] = { 0, };
	int top = 0;
	stack[top++] = t;
	while (P[t] != s && P[t] != NIL) {
		t = P[t]; stack[top++] = t;
	}
	if (s == P[t]) {
		printf("path : %c ->", s + 'A');
		while (top) {
			printf("%c", stack[--top] + 'A');
			if (top) printf("->");
		}
		printf("\n");
	}
	else printf("unable to reach\n");
	
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
	for (i = 0; i<vertex; i++) {
		printf("%2c", i + 'A');
	}
	printf("\n");

	printf("    ");
	for (i = 0; i<vertex; i++) {
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
	char v1, v2;
	int w;
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			if (i == j) G[i][j] = 0;
			else		G[i][j] = INF;			
		}
	}
	scnaf("%d %d", &vertex, &edge);
	for (i = 0; i < edge; i++) {
		scanf("%c %c %d", &v1, &v2, &w);
		int u = v1 - 'A', v = v2 - 'A';
		G[u][v] = G[v][u] = w;
	}
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
	for (i = 0; i<vertex; i++) {
		printf("%3c", 'A' + i);
	}
	printf("\n");

	for (i = 0; i<vertex; i++) {
		printf("%3c", 'A' + i);
		for (j = 0; j<vertex; j++) {
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