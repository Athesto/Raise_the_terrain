#include "../demo.h"

void drawsquare(SDL_Instance instance);
void draw_matrix(SDL_Instance instance, int m_len);
int main(void)
{
	SDL_Instance instance;

	if (init_instance(&instance) != 0)
		return(1);

	while ("C is awesome")
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		if (poll_events() == 1)
			break;
		draw_matrix(instance, 8);
		SDL_RenderPresent(instance.renderer);
	}
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	return(0);
}

void drawsquare(SDL_Instance instance)
{
	int x1, x2, y1, y2;

	x1 = 10;
	x2 = 100;
	y1 = 10;
	y2 = 100;

	SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawLine(instance.renderer, x1, y1, x1, y2);
	SDL_RenderDrawLine(instance.renderer, x1, y2, x2, y2);
	SDL_RenderDrawLine(instance.renderer, x2, y2, x2, y1);
	SDL_RenderDrawLine(instance.renderer, x2, y1, x1, y1);
}

void draw_matrix(SDL_Instance instance, int m_len)
{
	typedef struct point
	{
		int x;
		int y;
		int len;
	} p_t;

	p_t o = {40, 40, 50};
	p_t cell;
	int row, col;
	p_t pend;
	pend.x = o.x + o.len * m_len;
	pend.y = o.y + o.len * m_len;

	SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	cell.x = o.x;
	cell.y = o.y;
	cell.len = o.len;
	for (col = 0; col < m_len; col++)
	{
		for (row = 0; row < m_len; row++)
		{
			SDL_RenderDrawLine(instance.renderer, cell.x, cell.y, cell.x + cell.len, cell.y); /* uL */
			SDL_RenderDrawLine(instance.renderer, cell.x, cell.y, cell.x, cell.y + cell.len); /* ^-> */
			cell.x +=cell.len;
		}
		cell.x = o.x;
		cell.y +=cell.len;
	}

	SDL_RenderDrawLine(instance.renderer, o.x, pend.y, pend.x, pend.y); /* x */
	SDL_RenderDrawLine(instance.renderer, pend.x, o.y, pend.x, pend.y); /* y */
}

