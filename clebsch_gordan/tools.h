#pragma once
#include <type_traits>
#include <cmath>
namespace DOGOQ {
	template<typename U, typename T>
	U round(T x) {
		static_assert(std::is_integral<U>::value && std::is_floating_point<T>::value, "The rule <int-type> round(<float-type>) is violated");
		return U(std::round(x) + T(1e-3));
	}
}
