#pragma once
#include <vector>
#include <array>
#include "Shader.hpp"
#include "env.hpp"
#include "Vec.hpp"
#include "Matrix.hpp"
#include "Membre.hpp"
#include "struct.hpp"

class Model {

	public:
		Model(std::vector<Vertex> vertices);
		Model(Model const & src);
		virtual ~Model(void);
		Model & operator=(Model const & rhs);

		void draw(const Shader &shader);
		void update();

		Membre	*mainMembre;

		Matrix	model;
		Matrix	view;
		Matrix	projection;

		bool toSee = false;
		uint32_t	nb_membres;

		std::string nextAnimation;
	private:
		int		_nb_vertex;
		GLuint	_vao;
		std::vector<Vertex> vertices;
		void	changeAnimation();
};
