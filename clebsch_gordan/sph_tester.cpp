#define DOGOQ_DEBUG
#include "cgloader.h"
#include "spherical_harmonics.h"
#include <iostream>
using namespace DOGOQ;

int main() {
	Ylm<double> a(1.0, 1, 1), b(2.0, 1, 1);
	CGloader<double> C("default");
	CGloader<double> D;
	std::cout << C(1.5, -0.5, 1.0, -1.0, 2.5, -1.5) << '\n';
	std::cout << D(1.5, -0.5, 1.0, -1.0, 2.5, -1.5) << '\n';
	std::cout << integrate(a, b) << '\n';
}
