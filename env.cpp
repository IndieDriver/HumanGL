#include "env.hpp"

Env::Env(int width, int height) {
  SDL_Init(SDL_INIT_VIDEO);
  this->window = SDL_CreateWindow("HumanGL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
  this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_SOFTWARE);
  SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(this->renderer);
  SDL_RenderPresent(this->renderer);
}

Env::~Env() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}
