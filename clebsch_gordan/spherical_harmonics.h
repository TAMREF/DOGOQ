#pragma once
/*
	Spherical Harmonics
	Author : TAMREF
*/
#include <type_traits>
namespace DOGOQ {
	template <typename T>
	class SphericalHarmonics {
	public:
		static_assert(std::is_floating_point<T>::value, "Coefficient of Spherical Harmonics Should be floating-type");
		T c;
		int m, l;
		SphericalHarmonics();
		SphericalHarmonics(int m, int l); //1.0 * Y_lm
		SphericalHarmonics(T c, int m, int l); //c * Y_lm
	};
	//alias of Spherical Harmonics: Ylm, SphHar
	template <typename T>
	using Ylm = SphericalHarmonics<T>;
	template <typename T>
	using SphHar = SphericalHarmonics<T>;
    template <typename T>
    T integrate(SphericalHarmonics<T> a, SphericalHarmonics<T> b); //2-integral : a*b dtau
	template <typename T>
	T integrate(SphericalHarmonics<T> a, SphericalHarmonics<T> b, SphericalHarmonics<T> c);
}

#include "impl/spherical_harmonics-impl.h"
