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
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));
	glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, boneIndex));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);
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

	std::array<Matrix, 5> bones;
	for (int i = 0; i < membres.size(); ++i)
	{
		bones[i] = modelMatrix(membres[i].transform);
	}

	Matrix MVP = getMVP(model, view, projection);



	glUniformMatrix4fv(glGetUniformLocation(shader.id, "MVP"), 1, GL_FALSE, (const GLfloat*)&MVP.mat4);

	glUniformMatrix4fv(glGetUniformLocation(shader.id, "bones"), 5, GL_FALSE, (const GLfloat*)&bones[0]);

	glBindVertexArray(this->_vao);
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}
