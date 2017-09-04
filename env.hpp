#pragma once
#include <OpenGL/gl3.h>
#include <SDL.h>

class Env {
	public:
		Env(int width, int height);
		Env(Env const & src);
		virtual ~Env(void);
		Env & operator=(Env const & rhs);
		SDL_Window *window;
		SDL_Renderer *renderer;
};
