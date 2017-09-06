#include "model.hpp"
#include "Animator.hpp"
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
	Animator animator;
	Shader shader("Shader/shader.frag", "Shader/shader.vert");
	bool quit = false;
	Model model(data);

	int	control_id = 0;

	//animator.loadAnim("Anims/walk.anim", &model);

	model.membres[0].childrens.push_back({&model.membres[1], {1.0f, 1.0f, 1.0f}});
	// model.membres[1].origin = {0.5f, 0.5f, 0.0f};
	// model.membres[1].childrens.push_back({&model.membres[2], {1.0f, 1.0f, 1.0f}});
	// model.membres[2].origin = {0.5f, 0.5f, 0.0f};

	while (!quit) {
		if (SDL_PollEvent(&env.sdlEvent) != 0) {
			if(env.sdlEvent.type == SDL_QUIT || env.sdlEvent.key.keysym.sym == SDLK_ESCAPE) {
				quit = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_q)
				model.membres[control_id].transform.position.y += 0.1;
			if (env.sdlEvent.key.keysym.sym == SDLK_e)
				model.membres[control_id].transform.position.y -= 0.1;
			if (env.sdlEvent.key.keysym.sym == SDLK_a)
				model.membres[control_id].transform.position.x += 0.1;
			if (env.sdlEvent.key.keysym.sym == SDLK_d)
				model.membres[control_id].transform.position.x -= 0.1;
			if (env.sdlEvent.key.keysym.sym == SDLK_w)
				model.membres[control_id].transform.position.z -= 0.1;
			if (env.sdlEvent.key.keysym.sym == SDLK_s)
				model.membres[control_id].transform.position.z += 0.1;
			if (env.sdlEvent.key.keysym.sym == SDLK_KP_8)
				model.membres[control_id].transform.rotation.x += 0.1;
			if (env.sdlEvent.key.keysym.sym == SDLK_KP_5)
				model.membres[control_id].transform.rotation.x -= 0.1;
			if (env.sdlEvent.key.keysym.sym == SDLK_KP_6)
				model.membres[control_id].transform.rotation.y += 0.1;
			if (env.sdlEvent.key.keysym.sym == SDLK_KP_4)
				model.membres[control_id].transform.rotation.y -= 0.1;
			if (env.sdlEvent.key.keysym.sym == SDLK_KP_7)
				model.membres[control_id].transform.rotation.z += 0.1;
			if (env.sdlEvent.key.keysym.sym == SDLK_KP_9)
				model.membres[control_id].transform.rotation.z -= 0.1;
			if (env.sdlEvent.key.keysym.sym == SDLK_1)
				control_id = 0;
			if (env.sdlEvent.key.keysym.sym == SDLK_2)
				control_id = 1;
		}
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		model.draw(shader);
		SDL_GL_SwapWindow(env.window);
	}
	return 0;
}
