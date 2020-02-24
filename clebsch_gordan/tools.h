#pragma once
#include <type_traits>
#include <cmath>
namespace DOGOQ {
	template<typename U, typename T>
	U round(T x) {
		static_assert(std::is_integral<U>::value && std::is_floating_point<T>::value, "The rule <int-type> round(<float-type>) is violated");
		return std::abs(x - U(x)) < 0.5 ? U(x) : std::abs(x - (U(x)+1)) < 0.5 ? U(x) + 1 : U(x) - 1;
	}
	template <typename T>
	constexpr T pi = T(3.141592653589793238462643383279502884L);
}
