#include<stdio.h>
#define MAX 1000
int a[MAX + 1];   // ���� ���� �迭 
int check[MAX + 1];
void dfs(int x);  // ���̿켱 Ž�� �Լ�
int main()
{
	int tc, ti;  // �׽�Ʈ ���̽� ����
	int n;   // �������� ������ ���� ����
	int i;
	int ans;  // �������� ����Ŭ�� ���� ���� 

	freopen("data.txt", "rt", stdin);
	scanf("%d", &tc);

	// TODO
	while(tc--){
		ans = 0;
		scanf("%d",&n);		
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			check[i] = 0;
		}
		for(int i=1;i<=n;i++){
			if( check[i] == 0 ) {
				dfs(i);
				ans++;
			}
		}
		printf("%d\n",ans);
	}	
	return 0;
}

void dfs(int x)
{
	// TODO
	if( check[x] ) return;
	check[x] = 1;
	dfs(a[x]);
}