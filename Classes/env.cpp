#include "env.hpp"

Env::Env(int w, int h) {
	width = w;
	height = h;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
	} else {
		this->window = SDL_CreateWindow("HumanGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
		if (this->window == NULL) {
			std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		} else {
			SDL_ShowCursor(SDL_DISABLE);
			SDL_WarpMouseInWindow(this->window, w / 2, h / 2);
			SDL_SetWindowGrab(this->window, SDL_TRUE);
			SDL_SetRelativeMouseMode(SDL_TRUE);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
			SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
			SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
			SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
			SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
			SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
			this->glContext = SDL_GL_CreateContext(window);
			if(glContext == NULL) {
				std::cout << "OpenGL context could not be created! SDL Error: " << SDL_GetError() << std::endl;
			}
			if (!gladLoadGLLoader(SDL_GL_GetProcAddress)) {
				std::cout << "Failed to initialize OpenGL context" << std::endl;
			}

			glEnable(GL_DEPTH_TEST);
			glDepthFunc(GL_LESS);

		}
	}
}

Env::~Env() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}
