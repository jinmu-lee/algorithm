#include <stdio.h>
#define MAX 10
int dist[MAX][MAX];				/* ����â��� ���ó, ���ó�� ���ó, ���ó�� ����â�� �Ÿ� ���� �迭 */
int R[MAX];						/* �� ��ǥ ���� �迭 */
int C[MAX];						/* �� ��ǥ ���� �迭 */
int N;							/* ������ ũ�� */
int delivery_cnt;				/* ��� �Ǽ� */
int perm[MAX];					/* �������� �迭 */
int used[MAX];					/* ���� üũ �迭 */
int best[MAX];					/* �ִ� ��� ���� �迭 */
int minV = MAX * MAX;			/* �ּҰŸ� ���庯�� */

void createPerm(int n, int k);	/* �������� �� �Ÿ���� �Լ� */

int main(void) {
	int i;
	int j;

	freopen("delivery_data.txt", "r", stdin);
	scanf("%d %d", &N, &delivery_cnt);	/* ���� ũ��� ��� �Ǽ��� �о���δ�. */

	/* ����â�� ��ǥ�� 1,1�� ���� */
	R[0] = 1;
	C[0] = 1;

	/* ���ó�� ��ǥ ������ �о�鿩 �迭�� ���� */
	for (i=1 ; i<=delivery_cnt ; i++) {
		scanf("%d %d", &R[i], &C[i]);
	}

	/* �� �������κ��� �� ���������� ���� ���̺��� �ۼ��Ѵ�. */

	// TODO

	printf("%2s", "");
	for (i=0 ; i<=delivery_cnt ; i++) {
		printf("%2d", i);
	}
	printf("\n");
	for (i=0 ; i<=delivery_cnt ; i++) {
		printf("%2d", i);
		for (j=0 ; j<=delivery_cnt ; j++) {
			printf("%2d", dist[i][j]);
		}
		printf("\n");
	}

	createPerm(0, delivery_cnt);  /* ������ �����ϴ� �Լ� ȣ�� */
	
	printf("�ִܰŸ� : %d\n", minV);
	printf("����â��> ");
	for (i=0 ; i<delivery_cnt ; i++) {
		printf("���ó %d > ", best[i]);
	}
	printf("����â�� ����\n");

	return 0;
}

/*------------------------------------------------------------------------
 * Function Name 	: createPerm() - ���� ���� �� �Ÿ���� �Լ�
 * Argument 		: n - ���� �迭 ���� ��ġ
 * 					  k - �迭 ���� �ε��� �Ѱ� ��
 * Return			: ����
 -----------------------------------------------------------------------*/
void createPerm(int n, int k) {
	int i;

	// TODO
	
}
