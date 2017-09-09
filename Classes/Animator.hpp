#pragma once
#include <string>
#include <fstream>
#include <cstdio>
#include "Model.hpp"
#include "struct.hpp"
#include "Vec.hpp"

class Animator {
	public:
		Animator(void);
		Animator(Animator const & src);
		virtual ~Animator(void);
		Animator & operator=(Animator const & rhs);
		void loadAnim(std::string filename, Model *model);
		void playAnim(std::string name, Model *model);
};
