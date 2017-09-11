#include "Model.hpp"


Model::Model(std::vector<Vertex> vert) {
	this->vertices = vert;
	GLuint	vbo; //One per vertex field

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	glGenVertexArrays(1, &this->_vao);
	glBindVertexArray(this->_vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
}

Model::Model(Model const & src) {
	*this = src;
}

Model::~Model(void) {

}

Model &	Model::operator=(Model const & rhs) {
	if (this != &rhs){

	}
	return (*this);
}

void	Model::draw(const Shader &shader) {
	shader.use();
	if (!this->nextAnimation.empty()) {
		changeAnimation();
	}
	mainMembre->applyTransform(nullptr);


	//Matrix MVP = getMVP(model, this->view, projMatrix(50, 1208/720));
	Matrix MVP = getMVP(this->model, viewMatrix({70, 0, 70}, {0, 0, 0}, {0, 1, 0}), this->projection);

	std::vector<Matrix> bones;
	std::vector<Vec4> colors;
	mainMembre->pushColor(colors);
	mainMembre->pushBone(bones);

	glUniformMatrix4fv(glGetUniformLocation(shader.id, "MVP"), 1, GL_FALSE, (const GLfloat*)&MVP.mat4);

	glUniformMatrix4fv(glGetUniformLocation(shader.id, "bones"), this->nb_membres, GL_FALSE, (const GLfloat*)bones.data());

	glUniform4fv(glGetUniformLocation(shader.id, "colors"), this->nb_membres, (const GLfloat*)colors.data());

	if (toSee)
	{
		printMatrix(bones[0].mat4);
		toSee = false;
	}

	glBindVertexArray(this->_vao);
//	glDrawArrays(GL_TRIANGLES, 0, vertices.size());
	glDrawArraysInstanced(GL_TRIANGLES, 0, vertices.size(), this->nb_membres);
}

void	Model::changeAnimation() {
	bool isEnded;
	isEnded = this->mainMembre->animationIsEnded();
	if (isEnded) {
		this->mainMembre->playAnimation(this->nextAnimation);
		this->nextAnimation.clear();
	}
}
