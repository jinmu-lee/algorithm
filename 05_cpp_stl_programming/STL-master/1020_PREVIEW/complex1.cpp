#include <iostream>
#include <complex>
using std::complex;
using std::sin;
using std::cout;
using std::endl;

using namespace std::literals;
//using namespace std;

#if 0

Some functions supported in a header of complex

Exponential : exp,log,log10
Power : pow, sqrt
Trigometric : sin, cos, tan, asin, acos, atan
Hyperbolic : sinh, cosh, tanh, asinh, acosh, atanh
refer to : cppreference.com

#endif

int main()
{
	complex<double> c1(1, 0);

	cout << c1 << endl;
	cout << c1.real() << endl;
	cout << c1.imag() << endl;

	complex<double> c2 = sin(c1);
	cout << c2 << endl;

#if 0
	complex<int> c3(1, 0); // complex type only support float / double
	complex<int> c4 = sin(c3); // Unexpected
#endif

	complex<float> c5(3); // 3, 0
	complex<float> c6(3, 1); // 3, 1
#if 0
	3.2f -> complex<double>
	3.2if -> complex<float>
	3.2lf -> complex<long double>
#endif
	complex<float> c7(3if); // 0, 3

	cout << c5 << endl;
	cout << c7 << endl;

}
