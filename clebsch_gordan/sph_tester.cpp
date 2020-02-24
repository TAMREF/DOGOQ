//#define DOGOQ_DEBUG remove the comment when you are on debugging
#include "cgloader.h"
#include "spherical_harmonics.h"
#include <iostream>
using namespace DOGOQ;

int main() {
	std::cout << std::fixed; std::cout.precision(8);
	Ylm<double> a(1.0, 1, 1), b(2.0, 1, 1), c(1.5, 1, -1);
	CGloader<double> C("C:/Users/SAMSUNG/Source/Repos/DOGOQ/clebsch_gordan/db.cgdata");
	CGloader<double> D;
	std::cout << C(1.5, -0.5, 1.0, -1.0, 2.5, -1.5) << '\n';
	std::cout << D(1.5, -0.5, 1.0, -1.0, 2.5, -1.5) << '\n';
	std::cout << integrate(a, b) << '\n';
	std::cout << integrate(a, b, c) << '\n';
	Ylm<double> x(1.0, 0, 0);
	std::cout << integrate(x, x) << '\n';
	std::cout << integrate(x, x, x) << '\n';
	system("pause");
}
