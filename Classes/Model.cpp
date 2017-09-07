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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	shader.use();

	membres[0].applyTransform();

	Matrix MVP = getMVP(model, viewMatrix({0,0,50}, {0,0,-1}, {0,1,0}), projMatrix(50, 1280/720));

	std::array<Matrix, 3> bones;
	for (int i = 0; i < 3; ++i)
	{
		bones[i] = membres[i].modelMat;
	}

	std::array<Vec4, 3>colors;
	colors[0] = {1.0f, 0.0f, 0.0f, 1.0f};
	colors[1] = {1.0f, 1.0f, 1.0f, 1.0f};
	colors[2] = {0.0f, 0.0f, 1.0f, 1.0f};

	glUniformMatrix4fv(glGetUniformLocation(shader.id, "MVP"), 1, GL_FALSE, (const GLfloat*)&MVP.mat4);

	glUniformMatrix4fv(glGetUniformLocation(shader.id, "bones"), 3, GL_FALSE, (const GLfloat*)&bones[0]);

	glUniform4fv(glGetUniformLocation(shader.id, "colors"), 3, (const GLfloat*)&colors[0]);

	if (toSee)
	{
		printMatrix(bones[0].mat4);
		toSee = false;
	}

	glBindVertexArray(this->_vao);
//	glDrawArrays(GL_TRIANGLES, 0, vertices.size());
	glDrawArraysInstanced(GL_TRIANGLES, 0, vertices.size(), 3);
}
