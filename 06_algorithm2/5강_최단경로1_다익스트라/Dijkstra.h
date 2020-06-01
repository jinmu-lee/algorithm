#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_
#define MAX 100
#define INF (MAX * MAX)
#define NIL -1

extern int G[MAX][MAX];	 // �׷��� ������� �迭 
extern int V[MAX];	     // ��� ��� üũ �迭 
extern int D[MAX];		 // �ִܰŸ� ���� �迭 
extern int P[MAX];		 // ������� ���� �迭 
extern int vertex;		 // ���� �� ���� 
extern int edge;		 // ���� �� ���� 

void initGraph(void);    //�׷��� �����͸� �о�鿩 �����࿭ ���� 
void printGraph(void);   //�׷��� �����࿭ ��� 
void dijkstra(int s);    // ���޵� �������� ���� ������ ���������� �ּ� ����ġ�� ����ϰ� ��θ� ������
void printDistance(int s);    // ������������ ���� �� ���������� �ּҰ���ġ�� �����ϰ� �ִ� �迭 ��� �Լ� 
void printPath(int s, int t); // ���� ����->�� ���������� path �� ����ġ ���
void printPredecessor(void);  // �������� ���� �迭 ��� �Լ� 

#endif /* DIJKSTRA_H_ */
