#pragma once
#include <vector>
#include "Shader.hpp"
#include "env.hpp"
#include "Vec.hpp"
#include "Matrix.hpp"

struct Vertex {
	Vec3 position;
	Vec3 normal;
	Vec3 color;
	float	boneIndex;
};

class Model {
	public:
		Model(std::vector<Vertex> vertices);
		Model(Model const & src);
		virtual ~Model(void);
		Model & operator=(Model const & rhs);
		void draw(const Shader &shader);
		Matrix	model;
		Matrix	view;
		Matrix	projection;
	private:
		int		_nb_vertex;
		GLuint	_vao;
		std::vector<Vertex> vertices;
};
