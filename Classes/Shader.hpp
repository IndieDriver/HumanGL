#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "env.hpp"

class Shader {
public:
	GLuint id = 0;
	Shader(std::string fragFilename, std::string vertexFilename);
	void use() const{
		glUseProgram(id);
	}

private:
	GLuint compileShader(std::string filename, GLuint shaderType);
	GLuint linkShaders(GLuint vertexID, GLuint fragID);
};

void    printShaderError(GLuint shade, std::string filename);
void    printLinkError(GLuint program, std::string vextexFilename, std::string fragmentFilename);
