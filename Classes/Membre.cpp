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
	this->modelMat = modelMatrix(this->transform);

	for (Child & child : childrens) {
		child.membre->applyTransform(this, child.jointure);
	}
}

void 	Membre::applyTransform(Membre *parent, Vec3 jointure) {
	//parent->color.print();
	if (parent != nullptr) {
		//this->transform = animation.updateTransform(transform);
		Transform newTrans = this->transform;
		newTrans.position -= jointure;
		this->modelMat = modelMatrix(newTrans) * parent->modelMat;
	}
	for (Child & child : childrens) {
		child.membre->applyTransform(this, child.jointure);
	}
}

std::vector<Vec4> Membre::pushColor(std::vector<Vec4> &colors) {
	colors.push_back(this->color);
	for (Child & child : childrens) {
		colors = child.membre->pushColor(colors);
	}
	return (colors);
}

void Membre::pushBone(std::vector<Matrix> &bones) {
	bones.push_back(this->modelMat);
	for (Child & child : childrens) {
		child.membre->pushBone(bones);
	}
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
