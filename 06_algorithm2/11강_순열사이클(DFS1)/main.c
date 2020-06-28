#include<stdio.h>
#define MAX 1000
int a[MAX + 1];   // 순열 저장 배열 
int check[MAX + 1];
void dfs(int x);  // 깊이우선 탐색 함수
int main()
{
	int tc, ti;  // 테스트 케이스 저장
	int n;   // 순열내의 숫자의 개수 저장
	int i;
	int ans;  // 순열내의 사이클의 개수 저장 

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