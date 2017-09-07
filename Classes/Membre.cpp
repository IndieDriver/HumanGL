#include "Membre.hpp"

Membre::Membre(void) {
	origin = Vec3();
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

void printvec(Vec3 vec)
{
	std::cout << "x : " << vec.x << " y: " << vec.y << " z: " << vec.z << std::endl;
}

void 	Membre::applyTransform() {
	this->modelMat = modelMatrix(this->transform);
	for (Child & children : childrens) {
		children.membre->applyTransform(this, children.jointure);
	}
}

void 	Membre::applyTransform(Membre *parent, Vec3 jointure) {
	Transform newTr = this->transform;
	newTr.position -= jointure;
	this->modelMat =  modelMatrix(newTr) * parent->modelMat;
	for (Child & children : childrens) {
		children.membre->applyTransform(this, children.jointure);
	}
}
