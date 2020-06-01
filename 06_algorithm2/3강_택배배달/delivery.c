#include <stdio.h>
#define MAX 10
int dist[MAX+1][MAX+1];				/* ����â��� ���ó, ���ó�� ���ó, ���ó�� ����â�� �Ÿ� ���� �迭 */
int R[MAX];						/* �� ��ǥ ���� �迭 */
int C[MAX];						/* �� ��ǥ ���� �迭 */
int N;							/* ������ ũ�� */
int delivery_cnt;				/* ��� �Ǽ� */
int perm[MAX];					/* �������� �迭 */
int used[MAX];					/* ���� üũ �迭 */
int best[MAX];					/* �ִ� ��� ���� �迭 */
int minV = MAX * MAX;			/* �ּҰŸ� ���庯�� */

void createPerm(int n, int k);	/* �������� �� �Ÿ���� �Լ� */
inline int abs(int a) { return a >= 0 ? a : -a; }
int main(void) {
	int i;
	int j;

	freopen("delivery_data.txt", "r", stdin);
	scanf("%d %d", &N, &delivery_cnt);	/* ���� ũ��� ��� �Ǽ��� �о���δ�. */

										/* ����â�� ��ǥ�� 1,1�� ���� */
	R[0] = 1;
	C[0] = 1;

	/* ���ó�� ��ǥ ������ �о�鿩 �迭�� ���� */
	for (i = 1; i <= delivery_cnt; i++) {
		scanf("%d %d", &R[i], &C[i]);
	}

	/* �� �������κ��� �� ���������� ���� ���̺��� �ۼ��Ѵ�. */

	// TODO
	for (int i = 0; i <= delivery_cnt; i++) {
		for (int j = 0; j <= delivery_cnt; j++) {
			int weight = abs(R[i] - R[j]) + abs(C[i] - C[j]);
			dist[i][j] = dist[j][i] = weight;
		}
	}
	printf("%2s", "");
	for (i = 0; i <= delivery_cnt; i++) {
		printf("%2d", i);
	}
	printf("\n");
	for (i = 0; i <= delivery_cnt; i++) {
		printf("%2d", i);
		for (j = 0; j <= delivery_cnt; j++) {
			printf("%2d", dist[i][j]);
		}
		printf("\n");
	}

	createPerm(0, delivery_cnt);  /* ������ �����ϴ� �Լ� ȣ�� */

	printf("�ִܰŸ� : %d\n", minV);
	printf("����â��> ");
	for (i = 0; i<delivery_cnt; i++) {
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
	if (n == k) {
		int d = 0;
		for (int i = 0; i < k; i++) {
			if (i == 0) d += dist[0][perm[i]];
			else d += dist[perm[i - 1]][perm[i]];
		}
		d += dist[perm[k - 1]][0];
		printf("total dist = %d\n", d);
		if (d < minV) {
			minV = d;
			for (int i = 0; i < k; i++) {
				best[i]=perm[i];
			}
		}
		return;
	}
	for (i = 0; i < k; i++) {
		if (used[i]) continue;
		used[i] = 1;
		perm[n] = i + 1;
		createPerm(n + 1, k);
		used[i] = 0;
	}
}
