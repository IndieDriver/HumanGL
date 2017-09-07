#include "model.hpp"
#include "Animator.hpp"
#include "Shader.hpp"
#include "env.hpp"
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
	Animator animator;
	Skeleton skel;
	Shader shader("Shader/shader.frag", "Shader/shader.vert");
	bool quit = false;
	Model model(data);
	//Membre lharm = Membre;
	//lham.origin = Vec3(0.0f, 0.0f, 0.0f);
	//model.membres[0].childrens.push_back({{0.0f, 0.0f, 0.0f}});

	skel.loadSkeleton("human.skel", &model);
	animator.loadAnim("Anims/walk.anim", &model);

	while (!quit) {

		//model.membres[0].transform.rotation.y += 0.010f;

		if (SDL_PollEvent(&env.sdlEvent) != 0) {
			if(env.sdlEvent.type == SDL_QUIT || env.sdlEvent.key.keysym.sym == SDLK_ESCAPE) {
				quit = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_q)
			{
				model.mainMembre->transform.position.y += 0.1;
				model.toSee = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_e)
			{
				model.mainMembre->transform.position.y -= 0.1;
				model.toSee = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_a)
			{
				model.mainMembre->transform.position.x += 0.1;
				model.toSee = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_d)
			{
				model.mainMembre->transform.position.x -= 0.1;
				model.toSee = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_w)
			{
				model.mainMembre->transform.position.z -= 0.1;
				model.toSee = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_s)
			{
				model.mainMembre->transform.position.z += 0.1;
				model.toSee = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_KP_8)
			{
				model.mainMembre->transform.rotation.x += 0.1;
				model.toSee = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_KP_5)
			{
				model.mainMembre->transform.rotation.x -= 0.1;
				model.toSee = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_KP_6)
			{
				model.mainMembre->transform.rotation.y += 0.1;
				model.toSee = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_KP_4)
			{
				model.mainMembre->transform.rotation.y -= 0.1;
				model.toSee = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_KP_7)
			{
				model.mainMembre->transform.rotation.z += 0.1;
				model.toSee = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_KP_9)
			{
				model.mainMembre->transform.rotation.z -= 0.1;
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
