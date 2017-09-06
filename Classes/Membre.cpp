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
	//this->modelMat = modelMatrix(this->transform) * parent->model-mat;
	Vec3 newpos = this->origin + jointure;
	Vec4 newPos = parent->modelMat * Vec4(newpos.x ,newpos.y, newpos.z ,1.0f);

	Transform newTrans; 

	newTrans.position = {
		newPos.w != 0 ? newPos.x / newPos.w : newPos.x ,
		newPos.w != 0 ? newPos.y / newPos.w : newPos.y ,
		newPos.w != 0 ? newPos.z / newPos.w : newPos.z}; 


	newTrans.rotation = parent->modelMat * Vec4(newpos.x ,newpos.y, newpos.z ,1.0f);

	newTrans.scale = {1.0f, 1.0f, 1.0f};

	this->modelMat = modelMatrix(newTrans);
	for (Child & children : childrens) {
		children.membre->applyTransform(this, children.jointure);
	}
}
