/*
	Clebsch-Gordan Coefficient DB loader
	Author : TAMREF
*/
#pragma once
#include <map>
#include <string>
#include <tuple>
#include <type_traits>
#include "ndvector.h"

namespace DOGOQ {
	template <typename T> //T : double, float, long double...
	class CGloader {
		static_assert(is_floating_point<T>::value, "Instantiation of CGloader should be done with floating point type");
		//TODO : Replace data type of CGloader
		using d6 = std::tuple<int, int, int, int, int, int>;
		std::map<d6, T> dat;
	public:
		static const std::string fname = "db.cgdata";
		explicit CGloader(const std::string F = fname);
		~CGloader();
		T operator() (d6 f) const;
		T operator() (int j1, int m1, int j2, int m2, int J, int M) const;
	};
}

#include "impl/cgloader-impl.h"