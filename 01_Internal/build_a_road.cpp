#include <iostream>
#include <queue>
using namespace std;
const int INF = 1e9;
const int dy[] = {1,0,-1,0};
const int dx[] = {0,1,0,-1};
int N;//지도 크기
char map[110][110];//지도 정보
int dp[110][110];
struct Node{
	int y,x;
	Node(int y,int x):y(y),x(x){}
};

void Input_Data(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> map[i];
	}
}

int main(){
	int ans = -1;
	Input_Data();		//	입력 함
	//	코드를 작성하세요
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			dp[i][j]= INF;
		}
	} 
	queue<Node> q;
	q.push(Node(0,0));
	dp[0][0] = map[0][0] - '0';
	while(!q.empty()){
		Node n = q.front(); q.pop();
		for(int i=0;i<4;i++){
			int ny = n.y + dy[i];
			int nx = n.x + dx[i];
			if( ny < 0 || ny >= N || nx < 0 || nx >= N ) continue;
			int next = map[ny][nx] - '0';
			if( dp[ny][nx] > dp[n.y][n.x] + next ){
				dp[ny][nx] = dp[n.y][n.x] + next;
				q.push(Node(ny,nx));
			}
		}
	}
	ans = dp[N-1][N-1];
	cout << ans << endl;	//	정답 출력
	return 0;
}

