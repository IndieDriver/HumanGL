#pragma once
#include <string>
#include <fstream>
#include <cstdio>
#include "model.hpp"
#include "struct.hpp"
#include "Vec.hpp"

class Animator {
	public:
		Animator(void);
		Animator(Animator const & src);
		virtual ~Animator(void);
		Animator & operator=(Animator const & rhs);
		void loadAnim(std::string filename, Model *model);
};