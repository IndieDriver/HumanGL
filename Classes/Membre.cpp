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

void 	Membre::applyTransform(Membre *parent) {
	transform = animation.updateTransform(transform);

	if (parent != nullptr) {

		//transform = transform * parent->transform; //a decomposer
	}
	for (Child & children : childrens) {
		children.membre->applyTransform(this);
	}
}
