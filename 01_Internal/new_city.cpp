#include <iostream>
using namespace std;
const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,-1,1};
const int dd[] = {1,0,3,2};
int N;//정사각형 지도 크기
int X, Y;//수돗물 공급되는 시작 좌표, 가로, 세로
int map[20][20];//지도 정보
bool visited[20][20];
int total_count;
const int pipe[12][4] = { {0,0,0,0}, {0,0,1,1}, {1,1,0,0}, {0,1,0,1},
	{0,1,1,1}, {1,0,1,0}, {1,0,0,1}, {1,1,0,1},
	{0,1,1,1}, {1,1,1,0}, {1,0,1,1},{1,1,1,1}};

void Input_Data(void){
	char str[20];
	cin >> N;
	cin >> X >> Y;
	for (int i = 0; i < N; i++){
		cin >> str;
		for(int j = 0; j < N; j++){
			if(str[j] < 'A') map[i][j] = str[j] - '0';
			else map[i][j] = str[j] - 'A' + 10;
			if( map[i][j] ) total_count++;
		}
	}
}
void dfs(int y,int x){
	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if( ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] ) continue;
		if( pipe[map[y][x]][i] == 1 && pipe[map[ny][nx]][dd[i]] == 1){
			visited[y][x] = visited[ny][nx] = true;
			dfs(ny,nx);
		}
	}
}

int main(){
	int ans = -1;
	Input_Data();		//	입력 함수

	//	코드를 작성하세요
	dfs(Y,X);
	int count = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if( visited[i][j] ) count++;
		}
	}
	ans = total_count - count;
	cout << ans << endl;	//	정답 출력
	return 0;
}

