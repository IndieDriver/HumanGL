#pragma once
#include <vector>
#include "Model.hpp"
#include "Vec.hpp"
#include "Matrix.hpp"

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
		std::vector<Vertex>		vertices;
		Vec3					origin;
		Matrix					transform;
		void applyTransform(Membre *parent);
};
