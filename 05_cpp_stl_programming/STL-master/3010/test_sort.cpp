#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	//list<int> v = { 10,1,9,2,8,3,7,4,6,5 };
	//vector<int> v = { 10,1,9,2,8,3,7,4,6,5 };
	forward_list<int> v = { 10,1,9,2,8,3,7,4,6,5 };
	
	sort(begin(v), end(v));

	for (auto& n : v)
		cout << n << ", ";
	
	



}
