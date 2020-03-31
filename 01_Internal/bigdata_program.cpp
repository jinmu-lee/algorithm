#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;
typedef pair<string,int> psi;
int N;
string str[10001];
map<string,int> mp;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>str[i];
		mp[str[i]]++;
	} 
	vector<psi> v(mp.begin(),mp.end());
	sort(v.begin(),v.end(),[](psi a,psi b){return a.second>b.second;});
	long long int sum = 0;
	for(int i=0;i<v.size();i++){
		if( v[i].second >= 2 ){
			cout<<v[i].first<<" ";
			for(int j=0;j<N;j++){
				if(str[j].compare(v[i].first) == 0 ){
					cout<<j+1<<" ";
				}
			}
			cout<<"\n";
			sum += v[i].second;
		}
		if( (double)sum >= ((double)N/(double)2) ) break;
	}
	if( sum == 0 ) cout<<"unique\n";
	return 0;
}

