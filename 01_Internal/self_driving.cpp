#include <iostream>
#include <queue>
using namespace std;
const int dy[] = {1,0,-1,0};
const int dx[] = {0,1,0,-1};
int H;//세로크기
int W;//가로크기
char map[500][510];//지도
bool visited[501][501];

struct Node{
	int y,x,k;
	Node(int y,int x,int k):y(y),x(x),k(k){}
};

void input_data(){
	int i;
	cin >> H >> W;
	for(i=0 ; i<H ; i++){
		cin >> map[i];
	}
}
int bfs(){
	queue<Node> q;
	q.push(Node(0,0,0));
	visited[0][0] = true;
	while(!q.empty()){
		Node n = q.front(); q.pop();
		if( n.y == H-1 && n.x == W-1 ) return n.k;
		for(int i=0;i<4;i++){
			int ny = n.y + dy[i];
			int nx = n.x + dx[i];
			if( ny < 0 || ny >= H || nx < 0 || nx >= W ) continue;
			if( visited[ny][nx] || map[ny][nx] != '.' ) continue;
			visited[ny][nx] = true;
			q.push(Node(ny,nx,n.k+1));
		}
	}
	return -1;
}

int main(){
	int ans = 0;
	input_data();
	//	코드를 작성하세요
	ans = bfs();
	cout << ans << endl;
	return 0;
}
