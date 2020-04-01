#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,L,H;						//	문화재의 개수
struct Node{
	int width,height;	
	Node(int width,int height):width(width),height(height){}
};
vector<Node> v;
int max_height,max_width;

int Solve(void){
	int area=0;

	cin >> N;							// 문화재의 개수 입력

	//	코드를 작성하세요
	for(int i=0;i<N;i++){
		int w,h; cin>>w>>h;
		v.push_back(Node(w,h));		
	}
	sort(v.begin(),v.end(),[](Node a,Node b){return a.width<b.width;});
	int max_idx = 0;
	int max_height = v[0].height;
	for(int i=1;i<N;i++){
		if( max_height < v[i].height ){
			max_idx = i;
			max_height = v[i].height;
		}
	}
	int sum = max_height;
	int height = v[0].height;
	int width = v[0].width;
	for(int i=1;i<=max_idx;i++){
		if( height <= v[i].height ){
			sum += abs(v[i].width-width)*height;
			height = v[i].height;
			width = v[i].width;			
		}		
	}
	height = v[N-1].height;
	width = v[N-1].width;
	for(int i=N-2;i>=max_idx;i--){
		if(height <= v[i].height){
			sum += abs(v[i].width-width)*height;
			height = v[i].height;
			width = v[i].width;
		}
	}
	area = sum;
	return area;
}

int main(void){
	int area;

	area = Solve(); 				// 문제 풀이

	cout << area << endl;		// 정답 출력
	return 0;
}
