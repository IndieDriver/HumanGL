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
	if (this->_animID != -1 && this->_animID < animations.size()) {
		this->transform = animations[_animID].updateTransform(transform);
	}
	this->modelMat = modelMatrix(this->transform);

	for (Child & child : childrens) {
		child.membre->applyTransform(this, child.jointure);
	}
}

void 	Membre::applyTransform(Membre *parent, Vec3 jointure) {
	if (parent != nullptr) {
		if (this->_animID != -1 && this->_animID < animations.size()) {
			this->transform = animations[_animID].updateTransform(transform);
		}

		Transform newTrans = this->transform;

		newTrans.position -= jointure;

		Matrix scalinInv = modelMatrix ({0,0,0}, {0,0,0}, {1/parent->transform.scale.x, 1/parent->transform.scale.y, 1/parent->transform.scale.z});
		this->modelMat = scalinInv * parent->modelMat;
		this->modelMat = modelMatrix(newTrans) * this->modelMat;
		this->modelMat = modelMatrix ({-this->origin.x,-this->origin.y,-this->origin.z}, {0,0,0}, {1,1,1}) * this->modelMat;
	}
	for (Child & child : childrens) {
		child.membre->applyTransform(this, child.jointure);
	}
}

void	Membre::pushColor(std::vector<Vec4> &colors) {
	colors.push_back(this->color);
	for (Child & child : childrens) {
		child.membre->pushColor(colors);
	}
}

void Membre::pushBone(std::vector<Matrix> &bones) {
	bones.push_back(this->modelMat);
	for (Child & child : childrens) {
		child.membre->pushBone(bones);
	}
}

void Membre::pushMembre(std::vector<Membre*> &membreVect) {
	membreVect.push_back(this);
	for (Child & child : childrens) {
		child.membre->pushMembre(membreVect);
	}
}

void	Membre::playAnimation(std::string animName) {
	if (_animID != -1 && _animID < animations.size()) {
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
	for (Child &child : this->childrens) {
		child.membre->playAnimation(animName);
	}
}
