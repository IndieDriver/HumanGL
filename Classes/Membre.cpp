#include "Membre.hpp"

Membre::Membre(void) {
	origin = Vec3();
	_animID = -1;
}

Membre::Membre(Membre const & src) {
	*this = src;
}

Membre::~Membre(void) {

}

Membre &	Membre::operator=(Membre const & rhs) {
	if (this != &rhs){

	}
	return (*this);
}

void 	Membre::applyTransform(Membre *parent) {
	//parent->color.print();
	//transform = animations[i].updateTransform(transform);

	if (parent != nullptr) {

		//transform = transform * parent->transform; //a decomposer
	}
	for (Child & child : childrens) {
		child.membre->applyTransform(this);
	}
}

std::vector<Vec4> Membre::pushColor(std::vector<Vec4> &colors) {
	colors.push_back(this->color);
	for (Child & child : childrens) {
		colors = child.membre->pushColor(colors);
	}
	return (colors);
}

std::vector<Matrix> Membre::pushBone(std::vector<Matrix> &bones) {
	bones.push_back(modelMatrix(this->transform));
	for (Child & child : childrens) {
		bones = child.membre->pushBone(bones);
	}
	return (bones);
}

void	Membre::playAnimation(std::string animName) {
	if (_animID != -1) {
		animations[this->_animID].reset();
	}
	int id = 0;
	for (Animation &animation : animations) {
		if (animation.name == animName) {
			_animID = id;
			animations[this->_animID].reset();
			return ;
		}
		id++;
	}
	_animID = -1;
}
