#include "../demo.h"

void draw_stuff(SDL_Instance instance);

int main(void)
{
	SDL_Instance instance;
	if (init_instance(&instance) != 0)
		return(1);

	while ("C is awesome")
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		draw_stuff(instance);
		SDL_RenderPresent(instance.renderer);
	}

	return(0);
}


