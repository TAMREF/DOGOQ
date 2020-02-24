/*
	Details of spherical harmonics
	Author : TAMREF
*/
#ifdef DOGOQ_DEBUG
	#include <iostream>
#endif
#include <cmath>
#include "../tools.h"

namespace DOGOQ {
	template <typename T>
	SphericalHarmonics<T>::SphericalHarmonics() :m(0), l(0), c(0) {}
	template <typename T>
	SphericalHarmonics<T>::SphericalHarmonics(int l, int m) : c(T(1)), l(0), m(0) {}
	template <typename T>
	SphericalHarmonics<T>::SphericalHarmonics(T c, int l, int m) : c(c), l(l), m(m) {}
	template <typename T>
	T integrate(SphericalHarmonics<T> a, SphericalHarmonics<T> b) {
		return a.c* b.c* T((a.l == b.l) && (a.m == b.m)); //What if |a.m| > a.l?
	}
	template <typename T>
	T integrate(SphericalHarmonics<T> left, SphericalHarmonics<T> mid, SphericalHarmonics<T> right) {
		//std::cout << "야 이거 짜라\n";
		CGloader<T> cg;
		int g1 = (2 * left.l + 1) * (2 * mid.l + 1) * (2 * right.l + 1);
		//std::cout << "coeff = " << cg(left.l, 0, mid.l, 0, right.l, 0) << ' ' << cg(left.l, left.m, mid.l, mid.m, right.l, right.m) << '\n';
		//std::cout << pi<T> << '\n';
		//std::cout << g1 << ' ' << std::sqrt((T)g1) << '\n';
		return left.c * mid.c * right.c * (std::sqrt((T)g1 / pi<T> / T(4))) * cg(left.l, 0, mid.l, 0, right.l, 0) * cg(left.l, left.m, mid.l, mid.m, right.l, right.m);
	}
}