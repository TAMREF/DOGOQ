#pragma once
/*
	Detailed implementation of cgloader.h
	Author : TAMREF
*/
#include <cassert>
#include <map>
#include <tuple>
#include <fstream>
#include "../tools.h"
#include <iostream>
#include <algorithm>

namespace DOGOQ {
	template<typename T>
	const std::string CGloader<T>::fname = "db.cgdata";
	template <typename T>
	CGloader<T>* CGloader<T>::ori = nullptr;

	template<typename T>
	CGloader<T>::CGloader() {}
    template<typename T>
	CGloader<T>::CGloader(const std::string arg) {
	    const std::string F = (arg == std::string("default") ? fname : arg);
		std::ifstream fin(F);
		//std::cout << "Input file : " << F << std::endl; 
		assert(fin.is_open());
		std::string G; //garbage
		while (fin.peek() != EOF) {
		    //std::cout << char(fin.peek()) << '\n';
		    if( fin.peek() == int('#')){
		        getline(fin, G);
		        continue;
		    }
			T j[3], m[3], res;
			assert(fin >> j[0] >> m[0] >> j[1] >> m[1] >> j[2] >> m[2] >> res);
			int jj[3], mm[3];
			for (int i = 0; i < 3; i++) {
				jj[i] = round<int>(j[i] * 2.L);
				mm[i] = round<int>(m[i] * 2.L);
			}
			//{for(int i = 0; i < 3; i++) std::cout << jj[i] << ' ' << mm[i] << ' '; std::cout << '\n';}
			dat[std::make_tuple(jj[0], mm[0], jj[1], mm[1], jj[2], mm[2])] = res;
			fin.get();
		}
		std::cout << "DB size is " << dat.size() << std::endl;
		if(CGloader<T>::ori == nullptr) CGloader<T>::ori = this;
	}
	template<typename T>
	inline CGloader<T>::~CGloader()
	{
	    if(CGloader<T>::ori == this) CGloader<T>::ori = nullptr;
	}
	template <typename T>
	//!TODO : change data type
	inline T CGloader<T>::operator() (d6 f) const {
	    //std::cout << CGloader<T>::ori << std::endl;
	    //std::cout << std::get<0>(f) << ' ' << std::get<1>(f) << ' ' << std::get<2>(f) << ' ' << std::get<3>(f) << ' ' << std::get<4>(f) << ' ' << std::get<5>(f) << '\n';
	    assert(CGloader<T>::ori != nullptr);
	    //std::cout << "count = " << CGloader<T>::ori->dat.count(f) << '\n';
	    return (CGloader<T>::ori->dat.count(f) ? CGloader<T>::ori->dat.at(f) : T(0));
		//if (!dat.count(f)) return T(0);
		//return dat[f];
	}

	template <typename T>
	inline T CGloader<T>::operator() (double j1, double m1, double j2, double m2, double J, double M) const {
	    assert(CGloader<T>::ori != nullptr);
	    if (j1 < j2){
	        std::swap(j1, j2);
	        std::swap(m1, m2);
	    }
	    auto X = std::make_tuple(round<int>(j1 * 2.L),
	                            round<int>(m1 * 2.L),
	                            round<int>(j2 * 2.L),
	                            round<int>(m2 * 2.L),
	                            round<int>(J  * 2.L),
	                            round<int>(M  * 2.L));
		return (*this)(X);
	}
}
