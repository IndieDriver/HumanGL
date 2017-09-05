#include "model.hpp"
#include "Shader.hpp"
#include "env.hpp"

std::vector<Vertex> data = {
	{{-1.0f, -1.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, 0},
	{{1.0f, -1.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, 0},
	{{0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, 0}
};

int main(int argc, char *argv[]) {
	Env env(1280, 720);
	Shader shader("shader.frag", "shader.vert");
	bool quit = false;
	Model model(data);
	while (!quit) {
		while (SDL_PollEvent(&env.sdlEvent) != 0) {
			if(env.sdlEvent.type == SDL_QUIT) {
				quit = true;
			}
		}
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		model.draw(shader);
		SDL_GL_SwapWindow(env.window);
	}
	return 0;
}
