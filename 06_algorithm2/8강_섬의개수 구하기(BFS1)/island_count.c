#include<stdio.h>
#define MAX 50
typedef enum{false, true} bool;

int a[MAX][MAX];      // ���� �ٴ� ���� ���� �迭 
int check[MAX][MAX];  // Ž������ üũ �迭 
int dx[] = { 0, 0, 1,-1, 1, 1,-1,-1 };  // 8���� Ž���� ���� x �����ǥ �迭 
int dy[] = { 1,-1, 0, 0, 1,-1, 1,-1 };  // 8���� Ž���� ���� y �����ǥ �迭 
int w, h;  // ������ �ʺ�, ����  ���庯��
int queue[MAX*MAX*2];  // �ʺ�켱 Ž�� �� ����� ���� queue 
int front, rear;       

int dataLoad();   // TC�� �ش��ϴ� ������ �о� ���̴� �Լ� 
bool inRange(int x, int y); // ���� ���� �˻� �Լ� 
void bfs(int x, int y);  // �ʺ�켱 Ž�� �Լ� 

int main()
{
	int cnt;
	int i, j, k, tc;
	
	freopen("land.txt", "rt", stdin);
	scanf("%d", &tc);
	
	for(k = 1; k<=tc; k++){
		cnt = 0;
		dataLoad();
		for (i = 0; i<h; i++) {
			for (j = 0; j<w; j++) {
				if (a[i][j] == 1 && check[i][j] == 0) {
					bfs(i, j);
					cnt++;   // ���� ���� count 
				}
			}
		}
		printf("���� ���� : %d��\n", cnt);
	}
	return 0;
}
/*--------------------------------------------------------------------------------------
Function Name : bfs() - ����Ǿ��� ���� �ʺ�켱���� Ž���ϴ� �Լ� 
Argument      : x, y - Ž���� ������ x, y ��ǥ 
Return Valuse : ����
--------------------------------------------------------------------------------------*/
void bfs(int x, int y)
{
	// TODO

}
/*--------------------------------------------------------------------------------------
Function Name : dataLoad() - ���������ϳ��� ���� �ٴ� ������ �о �����ϰ� check�迭�� �ʱ�ȭ ��Ŵ 
Argument      : ����
Return Valuse : ����
--------------------------------------------------------------------------------------*/
int dataLoad()
{
	int i, j; /* iterator */
	scanf("%d %d", &w, &h);
	if (w == 0 && h == 0) return false;
	for (i = 0; i<h; i++) {
		for (j = 0; j<w; j++) {
			scanf("%d", &a[i][j]);  // ���� �ٴ��� ������  
			check[i][j] = 0;  // check �迭 �ʱ�ȭ 
		}
	}
	return true;
}
/*--------------------------------------------------------------------------------------
Function Name : inRange() - x, y ����üũ �Լ� 
Argument      : x, y - x, y ��ǥ �� 
Return Valuse : ���� �������� ��ġ�̸� true, ���� ���̸� false ���� 
--------------------------------------------------------------------------------------*/
bool inRange(int x, int y)
{
	if (0 <= x && x < h && 0 <= y && y < w) {
		return true;
	}
	else{
		return false;
	}
}
