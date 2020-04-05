#include <iostream>
#include <stack>

using namespace std;
long N,T;
long p[1000001],s[1000001];
long long result[1000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>N>>T;
	for(int i=0;i<N;i++){
		cin>>p[i]>>s[i];
		result[i] = p[i]+s[i]*T;
	}
	stack<long long> stk;
	for(int i=0;i<N;i++){
		while(!stk.empty() && stk.top() >= result[i]) stk.pop();
		stk.push(result[i]);
	}
	cout<<stk.size()<<"\n";
	return 0;
}
