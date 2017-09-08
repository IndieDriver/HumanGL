#include "env.hpp"
#include "Camera.hpp"
#include "model.hpp"
#include "Animator.hpp"
#include "Shader.hpp"
#include "Skeleton.hpp"


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
	SDL_ShowCursor(SDL_DISABLE);
	SDL_SetWindowGrab(env.window, SDL_TRUE);
	SDL_SetRelativeMouseMode(SDL_TRUE);
	Camera camera(Vec3(0.0f, 0.0f, 70.0f), env.width, env.height);
	Animator animator;
	Skeleton skel;
	Shader shader("Shader/shader.frag", "Shader/shader.vert");
	bool quit = false;
	Model model(data);
	skel.loadSkeleton("human.skel", &model);
	animator.loadAnim("Anims/walk.anim", &model);
	animator.loadAnim("Anims/jump.anim", &model);
	animator.playAnim("Anims/walk.anim", &model);

	while (!quit) {
		while (SDL_PollEvent(&env.sdlEvent) != 0) {
			switch (env.sdlEvent.type) {
				case SDL_QUIT:
					quit = true;
					break ;
				case SDL_MOUSEMOTION:
					camera.mouseXpos = env.sdlEvent.motion.xrel;
					camera.mouseYpos = env.sdlEvent.motion.yrel;
					camera.mouseMoved = true;
					break ;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_ESCAPE) {
				quit = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_j) {
				animator.playAnim("Anims/jump.anim", &model);
			}
		}
		const uint8_t* currentKeyStates = SDL_GetKeyboardState(NULL);
		camera.queryInput(currentKeyStates);
		camera.update();
		model.view = camera.view;
		model.projection = camera.proj;
		/*
		if (env.sdlEvent.key.keysym.sym == SDLK_q)
			model.mainMembre->transform.position.y += 0.1;
		if (env.sdlEvent.key.keysym.sym == SDLK_e)
			model.mainMembre->transform.position.y -= 0.1;
		if (env.sdlEvent.key.keysym.sym == SDLK_a)
			model.mainMembre->transform.position.x += 0.1;
		if (env.sdlEvent.key.keysym.sym == SDLK_d)
			model.mainMembre->transform.position.x -= 0.1;
		if (env.sdlEvent.key.keysym.sym == SDLK_w)
			model.mainMembre->transform.position.z -= 0.1;
		if (env.sdlEvent.key.keysym.sym == SDLK_s)
			model.mainMembre->transform.position.z += 0.1;
		if (env.sdlEvent.key.keysym.sym == SDLK_KP_8)
			model.mainMembre->transform.rotation.x += 0.1;
		if (env.sdlEvent.key.keysym.sym == SDLK_KP_5)
			model.mainMembre->transform.rotation.x -= 0.1;
		if (env.sdlEvent.key.keysym.sym == SDLK_KP_6)
			model.mainMembre->transform.rotation.y += 0.1;
		if (env.sdlEvent.key.keysym.sym == SDLK_KP_4)
			model.mainMembre->transform.rotation.y -= 0.1;
		if (env.sdlEvent.key.keysym.sym == SDLK_KP_7)
			model.mainMembre->transform.rotation.z += 0.1;
		if (env.sdlEvent.key.keysym.sym == SDLK_KP_9)
			 model.mainMembre->transform.rotation.z -= 0.1; */
		//}
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		model.draw(shader);
		SDL_GL_SwapWindow(env.window);
	}
	return 0;
}
