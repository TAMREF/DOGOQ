/*
	Details of spherical harmonics
	Author : TAMREF
*/
#ifdef DOGOQ_DEBUG
	#include <iostream>
#endif
namespace DOGOQ {
	template <typename T>
	SphericalHarmonics<T>::SphericalHarmonics() :m(0), l(0), c(0) {}
	template <typename T>
	SphericalHarmonics<T>::SphericalHarmonics(int m, int l) : c(T(1)), m(0), l(0) {}
	template <typename T>
	SphericalHarmonics<T>::SphericalHarmonics(T c, int m, int l) : c(c), m(m), l(l) {}
	template <typename T>
	T integrate(SphericalHarmonics<T> a, SphericalHarmonics<T> b) {
		return a.c* b.c* T((a.l == b.l) && (a.m == b.m));
	}
	template <typename T>
	T integrate(SphericalHarmonics<T> a, SphericalHarmonics<T> b, SphericalHarmonics<T> c) {
		std::cout << "야 이거 짜라\n";
		return T(0);
	}
}