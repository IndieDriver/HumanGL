#pragma once
#include <vector>
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

		Matrix					modelMat;
		Transform				transform;
		Vec3					color;

		void applyTransform(Membre *parent);
		void applyTransform(Membre *parent, Vec3 jointure);

		std::vector<Animation>	animations;
		void					playAnimation(std::string animName);
		void					pushMembre(std::vector<Membre*> &membre);
		void					pushBone(std::vector<Matrix> &bones);
		void					pushColor(std::vector<Vec4> &color);

	private:
		int32_t					_animID;
};
