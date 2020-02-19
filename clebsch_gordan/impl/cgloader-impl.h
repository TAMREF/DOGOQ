#pragma once
/*
	Detailed implementation of cgloader.h
	Author : TAMREF
*/
#include <cassert>
#include <map>
#include <tuple>
#include <fstream>
#include "clebsch_gordan/tools.h"
#include "..\cgloader.h"

namespace DOGOQ {

	explicit CGloader::CGloader(const std::string F = fname) {
		std::ifstream fin(F);
		std::string msg = "The input file " + F + " should not be null";
		assert((msg, !fin));
		std::string G; //garbage
		while (fin.peek() == int('#')) {
			getline(fin, G);
		}
		while (fin.peek() != EOF) {
			T j[3], m[3], res;
			assert(fin >> j[0] >> m[0] >> j[1] >> m[1] >> j[2] >> m[2] >> res);
			int jj[3], mm[3];
			for (int i = 0; i < 3; i++) {
				jj[i] = round(j[i] * 2.L);
				mm[i] = round(m[i] * 2.L);
			}
			dat[tie(jj[0], mm[0], jj[1], mm[1], jj[2], mm[2])] = res;
		}
	}
	template<typename T>
	inline CGloader<T>::~CGloader()
	{
	}
	template <typename T>
	//!TODO : change data type
	inline T CGloader<T>::operator() (d6 f) const {
		if (!dat.count(f)) return T(0);
		return dat[f];
	}

	template <typename T>
	inline T CGloader<T>::operator() (int j1, int m1, int j2, int m2, int J, int M) const {
		auto X = std::make_tuple(j1, m1, j2, m2, J, M);
		return (*this)(X);
	}
}