#include "env.hpp"

Env::Env(int width, int height) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
	} else {
		this->window = SDL_CreateWindow("HumanGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
		if (this->window == NULL) {
			std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		} else {
			this->glContext = SDL_GL_CreateContext(window);
			if(glContext == NULL) {
				std::cout << "OpenGL context could not be created! SDL Error: " << SDL_GetError() << std::endl;
			}
		}
	}
}

Env::~Env() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}
