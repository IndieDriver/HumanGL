#pragma once
#include <vector>
#include <string>
#include <ostream>
#include <cstdio>
#include "struct.hpp"
#include "Vec.hpp"
#include "Matrix.hpp"
#include "Animation.hpp"

class Membre;

struct Child {
	Membre *membre;
	Vec3	jointure;
};

class Membre {
	public:
		Membre(void);
		Membre(Membre const & src);
		virtual ~Membre(void);
		Membre & operator=(Membre const & rhs);

		std::vector<Child>		childrens;
		Vec3					origin;

		Transform				transform;
		Matrix					modelMat;

		void applyTransform();
		void applyTransform(Membre *parent, Vec3 jointure);
		
		Animation				animation;
};
