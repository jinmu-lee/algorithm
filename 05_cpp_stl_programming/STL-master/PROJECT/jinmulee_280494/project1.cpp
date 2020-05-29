#include <iostream>
using namespace std;

template<typename InputIterator,
	typename OutputIterator,
	typename Op>
	OutputIterator xcopy_if(InputIterator begin,
		InputIterator end,
		OutputIterator destBegin,
		Op Pr)
{
	while (begin != end)
	{
		if (Pr(*begin))
		{
			*destBegin++ = *begin;
		}
		++begin;
	}

	return destBegin;
}

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int y[10] = { 0 };
	xcopy_if(x, x + 10, y, [](int a) { return a % 2 == 0; });
	for (auto n : y)
		cout << n << endl;
}
// 출력 결과 : 2, 4, 6, 8, 10, 0,0,0,0,0