#include "env.hpp"
#include "Camera.hpp"
#include "Model.hpp"
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

Model 	*loadHuman() {
	Model *model = new Model(data);
	Animator animator;
	Skeleton skel;
	skel.loadSkeleton("human.skel", model);
	animator.loadAnim("Anims/walk.anim", model);
	animator.loadAnim("Anims/kame.anim", model);
	animator.loadAnim("Anims/jump.anim", model);
	animator.loadAnim("Anims/idle.anim", model);
	animator.playAnim("Anims/walk.anim", model);
	return (model);
}

Model	*loadSpider() {
	Model *model = new Model(data);
	Animator animator;
	Skeleton skel;
	skel.loadSkeleton("spider.skel", model);
	animator.loadAnim("Anims/spiderwalk.anim", model);
	animator.playAnim("Anims/spiderwalk.anim", model);
	return (model);
}

int main(int argc, char *argv[]) {
	Env env(1280, 720);
	Camera camera(Vec3(0.0f, 0.0f, 120.0f), env.width, env.height);
	Animator animator;
	Skeleton skel;
	Shader shader("Shader/shader.frag", "Shader/shader.vert");
	bool quit = false;
	Model *model = loadHuman();
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
		}
		const uint8_t* currentKeyStates = SDL_GetKeyboardState(NULL);
		if (currentKeyStates[SDL_SCANCODE_ESCAPE]) {
			quit = true;
		}
		if (currentKeyStates[SDL_SCANCODE_J]) {
			animator.playAnim("Anims/jump.anim", model);
		}
		if (currentKeyStates[SDL_SCANCODE_H]) {
			animator.playAnim("Anims/walk.anim", model);
		}
		if (currentKeyStates[SDL_SCANCODE_K]) {
			animator.playAnim("Anims/kame.anim", model);
		}
		if (currentKeyStates[SDL_SCANCODE_I]) {
			animator.playAnim("Anims/idle.anim", model);
		}
		if (currentKeyStates[SDL_SCANCODE_1]) {
			delete model;
			model = loadHuman();
		}
		if (currentKeyStates[SDL_SCANCODE_2]) {
			delete model;
			model = loadSpider();
		}
		camera.queryInput(currentKeyStates);
		camera.update();
		model->view = camera.view;
		model->projection = camera.proj;
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		model->draw(shader);
		SDL_GL_SwapWindow(env.window);
	}
	delete model;
	return 0;
}
