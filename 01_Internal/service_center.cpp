#include <iostream>
using namespace std;

int N,Q;
int T[101];
int engineer[6];

void Input_Data(void){	
	cin >> N >> Q;				// 엔지니어의 수, 고객의 수
	for(int i=1;i<=Q;i++){
		cin >> T[i];				// 고객의 업무처리 시간
	}
}

int main(void){
	int sol;

	Input_Data();				// 입력 함수

	//	코드를 작성하세요
	int index = 1;
	for(int i=1;i<=Q;i++){
		int min_idx = 1;
		for(int j=2;j<=N;j++){
			if( engineer[min_idx] > engineer[j] ){
				min_idx = j;
			}
		}
		engineer[min_idx] += T[i];
	}
	int mxx = -1e9;
	for(int i=1;i<=N;i++){
		if( engineer[i] > mxx ) mxx = engineer[i];
	}
	sol = mxx;
	cout << sol << endl;	// 정답 출력
	return 0;
}
