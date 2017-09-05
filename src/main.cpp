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
	Shader shader("Shader/shader.frag", "Shader/shader.vert");
	bool quit = false;
	Model model(data);
	KeyFrame keyFrame1 = {0, {{0.0f, 0.0f, 0.0f},
							{0.0f, 0.0f, 0.0f},
							{1.0f, 1.0f, 1.0f}}};
	KeyFrame keyFrame2 = {42, {{1.0f, 1.0f, 0.0f},
							{0.0f, 0.0f, 0.0f},
							{1.0f, 1.0f, 1.0f}}};
	KeyFrame keyFrame3 = {84, {{0.0f, 0.0f, 0.0f},
							{0.0f, 0.0f, 0.0f},
							{1.0f, 1.0f, 1.0f}}};
	model.membres[0].animation.keyFrames.push_back(keyFrame1);
	model.membres[0].animation.keyFrames.push_back(keyFrame2);
	model.membres[0].animation.keyFrames.push_back(keyFrame3);

	while (!quit) {
		if (SDL_PollEvent(&env.sdlEvent) != 0) {
			if(env.sdlEvent.type == SDL_QUIT || env.sdlEvent.key.keysym.sym == SDLK_ESCAPE) {
				quit = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_w)
			{
				model.membres[0].transform.position.z += 10;
			}
		}
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		model.draw(shader);
		SDL_GL_SwapWindow(env.window);
	}
	return 0;
}
