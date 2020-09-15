#include "../demo.h"

int main(void)
{
	SDL_Instance instance;
	if (init_instance(&instance) != 0)
		return(1);

	while ("C is awesome")
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		/*
		 * awesome things here \o/
		 */
		SDL_RenderPresent(instance.renderer);
	}

	return(0);
}
