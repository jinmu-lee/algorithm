#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MOD = 50000;
int N;//제품 수
struct st{
	int X, ID;//위치, 아이디
};
st A[50010];
int newid[MOD+1],total_count;

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> A[i].X >> A[i].ID;
	}
}
void make_new_id(){
	for(int i=0;i<N;i++){
		int nid = A[i].ID % MOD;
		for(int j=0;j<MOD;j++){
			if( newid[nid] == 0 ){
				total_count++;
				newid[nid] = A[i].ID;
				A[i].ID = nid;
				break;
			}else if( newid[nid] == A[i].ID ){
				A[i].ID = nid;
				break;
			}
			nid = (nid+1)%MOD;
		}
	}
}
int main(){
	int ans = 1e9;

	InputData();			//	입력 함수

	//	코드를 작성하세요
	sort(A,A+N,[](st a,st b){return a.X<b.X;});
	make_new_id();
	memset(newid,0,sizeof(newid));
	int i=0,j=0,count=0;
	while(true){
		while( (i < N) && (total_count > count) ){
			if( newid[A[i].ID]++ == 0 ) count++;
			i++;
		}
		if( total_count != count ) break;
		while( newid[A[j].ID] > 1 ) {
			newid[A[j].ID]--; j++;
		}
		ans = min(ans,A[i-1].X-A[j].X);
		count--; newid[A[j].ID]=0; j++;
	}	
	cout << ans << endl;	//	정답 출력
	return 0;
}

