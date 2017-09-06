#include "model.hpp"
#include "Shader.hpp"
#include "env.hpp"


std::vector<Vertex> data = {
	{{1.0f,   1.0f,  1.0f}, { 1.0f,  0.0f,  0.0f}},
	{{1.0f,  -1.0f,  1.0f}, { 1.0f,  0.0f,  0.0f}},
	{{1.0f,   1.0f, -1.0f}, { 1.0f,  0.0f,  0.0f}},
	{{1.0f,   1.0f, -1.0f}, { 1.0f,  0.0f,  0.0f}},
	{{1.0f,  -1.0f,  1.0f}, { 1.0f,  0.0f,  0.0f}},
	{{1.0f,  -1.0f, -1.0f}, { 1.0f,  0.0f,  0.0f}},
	{{ 1.0f,  1.0f,  1.0f}, { 0.0f,  0.0f,  1.0f}},
	{{-1.0f,  1.0f,  1.0f}, { 0.0f,  0.0f,  1.0f}},
	{{ 1.0f, -1.0f,  1.0f}, { 0.0f,  0.0f,  1.0f}},
	{{ 1.0f, -1.0f,  1.0f}, { 0.0f,  0.0f,  1.0f}},
	{{-1.0f, -1.0f,  1.0f}, { 0.0f,  0.0f,  1.0f}},
	{{-1.0f,  1.0f,  1.0f}, { 0.0f,  0.0f,  1.0f}},
	{{ 1.0f,  1.0f,  1.0f}, { 0.0f,  1.0f,  0.0f}},
	{{-1.0f,  1.0f, -1.0f}, { 0.0f,  1.0f,  0.0f}},
	{{-1.0f,  1.0f,  1.0f}, { 0.0f,  1.0f,  0.0f}},
	{{ 1.0f,  1.0f,  1.0f}, { 0.0f,  1.0f,  0.0f}},
	{{ 1.0f,  1.0f, -1.0f}, { 0.0f,  1.0f,  0.0f}},
	{{-1.0f,  1.0f, -1.0f}, { 0.0f,  1.0f,  0.0f}},
	{{-1.0f, -1.0f, -1.0f}, {-1.0f,  0.0f,  0.0f}},
	{{-1.0f, -1.0f,  1.0f}, {-1.0f,  0.0f,  0.0f}},
	{{-1.0f,  1.0f,  1.0f}, {-1.0f,  0.0f,  0.0f}},
	{{-1.0f, -1.0f, -1.0f}, {-1.0f,  0.0f,  0.0f}},
	{{-1.0f,  1.0f, -1.0f}, {-1.0f,  0.0f,  0.0f}},
	{{-1.0f,  1.0f,  1.0f}, {-1.0f,  0.0f,  0.0f}},
	{{-1.0f, -1.0f, -1.0f}, { 0.0f,  0.0f, -1.0f}},
	{{-1.0f,  1.0f, -1.0f}, { 0.0f,  0.0f, -1.0f}},
	{{ 1.0f,  1.0f, -1.0f}, { 0.0f,  0.0f, -1.0f}},
	{{-1.0f, -1.0f, -1.0f}, { 0.0f,  0.0f, -1.0f}},
	{{ 1.0f,  1.0f, -1.0f}, { 0.0f,  0.0f, -1.0f}},
	{{ 1.0f, -1.0f, -1.0f}, { 0.0f,  0.0f, -1.0f}},
	{{-1.0f, -1.0f, -1.0f}, { 0.0f, -1.0f,  0.0f}},
	{{ 1.0f, -1.0f,  1.0f}, { 0.0f, -1.0f,  0.0f}},
	{{-1.0f, -1.0f,  1.0f}, { 0.0f, -1.0f,  0.0f}},
	{{-1.0f, -1.0f, -1.0f}, { 0.0f, -1.0f,  0.0f}},
	{{ 1.0f, -1.0f, -1.0f}, { 0.0f, -1.0f,  0.0f}},
	{{ 1.0f, -1.0f,  1.0f}, { 0.0f, -1.0f,  0.0f}}
};

int main(int argc, char *argv[]) {

	Env env(1280, 720);
	Shader shader("Shader/shader.frag", "Shader/shader.vert");
	bool quit = false;
	Model model(data);

	while (!quit) {

		//model.membres[0].transform.rotation.y += 0.010f;

		if (SDL_PollEvent(&env.sdlEvent) != 0) {
			if(env.sdlEvent.type == SDL_QUIT || env.sdlEvent.key.keysym.sym == SDLK_ESCAPE) {
				quit = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_q)
			{
				model.membres[0].transform.position.y += 0.1;
				model.toSee = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_e)
			{
				model.membres[0].transform.position.y -= 0.1;
				model.toSee = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_a)
			{
				model.membres[0].transform.position.x += 0.1;
				model.toSee = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_d)
			{
				model.membres[0].transform.position.x -= 0.1;
				model.toSee = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_w)
			{
				model.membres[0].transform.position.z -= 0.1;
				model.toSee = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_s)
			{
				model.membres[0].transform.position.z += 0.1;
				model.toSee = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_KP_8)
			{
				model.membres[0].transform.rotation.x += 0.1;
				model.toSee = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_KP_5)
			{
				model.membres[0].transform.rotation.x -= 0.1;
				model.toSee = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_KP_6)
			{
				model.membres[0].transform.rotation.y += 0.1;
				model.toSee = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_KP_4)
			{
				model.membres[0].transform.rotation.y -= 0.1;
				model.toSee = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_KP_7)
			{
				model.membres[0].transform.rotation.z += 0.1;
				model.toSee = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_KP_9)
			{
				model.membres[0].transform.rotation.z -= 0.1;
				model.toSee = true;
			}
		}
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		model.draw(shader);
		SDL_GL_SwapWindow(env.window);
	}
	return 0;
}
