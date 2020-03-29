#include <iostream>
#include <algorithm>
using namespace std;
int N,L,M,c[101],r[101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>N>>L>>M;
	for(int i=0;i<M;i++) cin>>c[i]>>r[i];
	int find_max = -1e9;
	for(int height=1;height<L/2;height++){
		int width = L/2 - height;
		for(int i=0;i<M;i++){
			for(int j=i;j<M;j++){
				int sy = min( c[i],c[j] );
				int sx = min( r[i],r[j] );
				int count = 0;
				for(int k=0;k<M;k++){
					if( c[k] >= sy && c[k] <= sy+height && r[k] >= sx && r[k] <= sx+width ) count++;					
				}
				if( find_max < count ) find_max = count;
			}			
		}		
	}
	cout<<find_max<<"\n";	
	return 0;
}
