#include <stdio.h>
#include "Dijkstra.h"

int main(void) {
	int i;
	int start; // ��� ���� ���庯�� 

	freopen("data2.txt", "r", stdin);

	initGraph();
	printGraph();

	start = 1;  // B ���� ����  
	dijkstra(start);  // B ���� ����  
	printDistance(start);
	printPredecessor();

	printf("--- %c ���� �ּ� ��� �� ��� ---\n", start+'A');
	for (i=0 ; i<vertex ; i++) {
		printf("�ּҺ�� : %c -> %c : %d\n", start+'A', i + 'A', D[i]);
		printPath(start, i);
	}

	return 0;
}
