#include <stdio.h>
#include<limits.h>
#define MAX 10

int perm[MAX];					/* �������� �迭 */
int used[MAX];					/* ���� üũ �迭 */
int wtime[MAX][MAX];              /* ���κ� �ش� �۾��� �ҿ�ð� ���� �迭 */
int minV;                       /* �ּ� �۾��ð� ���� */

void work(int n, int k);

int main(void)
{
	int T;
	freopen("data.txt", "r", stdin);
	scanf("%d", &T); // test case�� �� �Է� �ޱ�
	for (int tc = 1; tc <= T; tc++)  // test case �� ��ŭ �ݺ�
	{
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			used[i] = 0; // used �ʱ�ȭ
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &wtime[i][j]);
			}
		}
		minV = INT_MAX; //  minV = 100; - ������ ���ǿ��� �ִ� 100 ���Ϸ� ���ص� �� 
		work(0, N);
		printf("%d\n", minV);
	}
}

/*----------------------------------------------------------------------
* Function Name 	: work() - ���� ���� �� �۾��ð� ��� �Լ�
* Argument 		: n - ���� �迭 ���� ��ġ
* 					  k - �迭 ���� �ε��� �Ѱ� ��
* Return value	: ����
----------------------------------------------------------------------*/
void work(int n, int k)
{

	// TODO
	if (n == k) {
		int weight = 0;
		for (int i = 0; i < n; i++) {
			weight += wtime[i][perm[i]];
		}
		if (weight < minV) {
			minV = weight;
		}
		return;
	}
	for (int i = 0; i < k; i++) {
		if (used[i]) continue;
		used[i] = 1;
		perm[n] = i;
		work(n + 1, k);
		used[i] = 0;
	}
}