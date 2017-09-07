#include "model.hpp"
#include "Animator.hpp"
#include "Shader.hpp"
#include "env.hpp"
#include "Skeleton.hpp"


void print_transform(Transform trans)
{
	std::cout << std::endl << "position : (" << trans.position.x << ", " << trans.position.y << ", " << trans.position.x << ")" << std::endl;
	std::cout << "rotation : (" << trans.rotation.x << ", " << trans.rotation.y << ", " << trans.rotation.x << ")" << std::endl;
	std::cout << "scale : (" << trans.scale.x << ", " << trans.scale.y << ", " << trans.scale.x << ")" << std::endl;

}

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
	skel.loadSkeleton("human.skel", &model);
	animator.loadAnim("Anims/walk.anim", &model);

	std::vector<Membre*> membreVect;
	model.mainMembre->pushMembre(membreVect);
	int curMem = 0;

	while (!quit) {

		if (SDL_PollEvent(&env.sdlEvent) != 0) {
			if(env.sdlEvent.type == SDL_QUIT || env.sdlEvent.key.keysym.sym == SDLK_ESCAPE) {
				quit = true;
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_t)
			{
				if (env.sdlEvent.key.repeat == 0 && env.sdlEvent.key.type == SDL_KEYDOWN)
				{
					std::cout << curMem << std::endl;
					curMem++;
					if (curMem == membreVect.size())
						curMem = 0;
				}
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_p)
			{
				if (env.sdlEvent.key.repeat == 0 && env.sdlEvent.key.type == SDL_KEYDOWN)
					print_transform(membreVect[curMem]->transform);
			}
			if (env.sdlEvent.key.keysym.sym == SDLK_q)
				membreVect[curMem]->transform.position.y += 0.1;
			if (env.sdlEvent.key.keysym.sym == SDLK_e)
				membreVect[curMem]->transform.position.y -= 0.1;
			if (env.sdlEvent.key.keysym.sym == SDLK_a)
				membreVect[curMem]->transform.position.x += 0.1;
			if (env.sdlEvent.key.keysym.sym == SDLK_d)
				membreVect[curMem]->transform.position.x -= 0.1;
			if (env.sdlEvent.key.keysym.sym == SDLK_w)
				membreVect[curMem]->transform.position.z -= 1;
			if (env.sdlEvent.key.keysym.sym == SDLK_s)
				membreVect[curMem]->transform.position.z += 1;
			if (env.sdlEvent.key.keysym.sym == SDLK_KP_8)
				membreVect[curMem]->transform.rotation.x += 0.1;
			if (env.sdlEvent.key.keysym.sym == SDLK_KP_5)
				membreVect[curMem]->transform.rotation.x -= 0.1;
			if (env.sdlEvent.key.keysym.sym == SDLK_KP_6)
				membreVect[curMem]->transform.rotation.y += 0.1;
			if (env.sdlEvent.key.keysym.sym == SDLK_KP_4)
				membreVect[curMem]->transform.rotation.y -= 0.1;
			if (env.sdlEvent.key.keysym.sym == SDLK_KP_7)
				membreVect[curMem]->transform.rotation.z += 0.1;
			if (env.sdlEvent.key.keysym.sym == SDLK_KP_9)
				membreVect[curMem]->transform.rotation.z -= 0.1;
		}
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		model.draw(shader);
		SDL_GL_SwapWindow(env.window);
	}
	return 0;
}
