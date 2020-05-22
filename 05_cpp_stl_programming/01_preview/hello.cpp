#include <iostream>

int main(){
	constexpr int c = 0;
	if constexpr ( c==0 )
		std::cout << "hello\n";
	return 0;
}
