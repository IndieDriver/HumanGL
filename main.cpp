#include "env.hpp"

int main(int argc, char *argv[]) {
	Env env(1280, 720);
	bool quit = false;
	while (!quit) {
		while (SDL_PollEvent(&env.sdlEvent) != 0) {
			if(env.sdlEvent.type == SDL_QUIT) {
				quit = true;
			}
		}
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		SDL_GL_SwapWindow(env.window);
	}
	return 0;
}
