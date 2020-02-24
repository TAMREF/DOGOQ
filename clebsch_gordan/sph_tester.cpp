#define DOGOQ_DEBUG
#include "cgloader.h"
#include "spherical_harmonics.h"
#include <iostream>
using namespace DOGOQ;

int main() {
	Ylm<double> a(1.0, 1, 1), b(2.0, 1, 1);
	std::cout << integrate(a, b) << '\n';
}
