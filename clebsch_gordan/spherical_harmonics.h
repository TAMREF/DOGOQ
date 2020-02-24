#pragma once
/*
	Spherical Harmonics
	Author : TAMREF
*/
#include <type_traits>
namespace DOGOQ {
	template <typename T>
	class SphericalHarmonics {
		static_assert(std::is_floating_point<T>::value, "Coefficient of Spherical Harmonics Should be floating-type");
		T c;
		int m, l;
	public:
		SphericalHarmonics();
		SphericalHarmonics(int m, int l); //1.0 * Y_lm
		SphericalHarmonics(T c, int m, int l); //c * Y_lm
		friend T integrate(SphericalHarmonics<T> a, SphericalHarmonics<T> b); //2-integral : a*b dtau
		friend T integrate(SphericalHarmonics<T> a, SphericalHarmonics<T> b, SphericalHarmonics<T> c);
	};
	//alias of Spherical Harmonics: Ylm, SphHar
	template <typename T>
	using Ylm = SphericalHarmonics<T>;
	template <typename T>
	using SphHar = SphericalHarmonics<T>;
}

#include "impl/spherical_harmonics-impl.h"