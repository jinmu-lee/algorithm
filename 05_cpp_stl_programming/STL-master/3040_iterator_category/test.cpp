#include <iostream>

using namespace std;
#if 0
constexpr void func(int a){
	a=10;
//	int b = a;
}
#endif
#if 0
constexpr int sum(int a,int b){
	return a+b;
}
#endif
const int sum(int a,int b){
	return a+b;
}


int main(){

//	const int a = 10;
//	constexpr int a = 10;
//	a = 11;
//	constexpr int a = 5;
//	func(a);
	int arr[sum(1,2)];
	cout<<sizeof(arr)/sizeof(arr[0])<<"\n";
}
