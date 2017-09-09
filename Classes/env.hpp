#pragma once
#include <glad/glad.h>
#include <SDL.h>
#include <iostream>

class Env {
	public:
		Env(int width, int height);
		Env(Env const & src);
		virtual ~Env(void);
		Env & operator=(Env const & rhs);
		SDL_Window *window;
		SDL_GLContext glContext;
		SDL_Event sdlEvent;
		int width;
		int height;
};
