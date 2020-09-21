#include "../demo.h"

void draw_altmatrix(SDL_Instance instance, int m_len);
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
		draw_altmatrix(instance, 8);
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

void draw_altmatrix(SDL_Instance instance, int m_len)
{
	typedef struct point
	{
		float x;
		float y;
		float z;
	} point_t;
	point_t point[8][8];
	point_t tmp[8][8];
	int col, row;
	int len = 10;
	int offset = 200;
	float inclination = 0.7;
	int zmatrix[8][8] = {
		{120, 60, 40, 60, 20, -20, -80, -120},
		{40, 20, 30, 30, -10, -40, -90, -110},
		{20, 30, 10, 6, -6, -20, -26, -90},
		{0, -6, 10, 10, -6, -20, -20, -40},
		{-20, -20, -18, -14, -40, -20, -20, -30},
		{-10, -10, -10, -10, -8, -20, -20, -30},
		{20, 10, 10, 10, 10, 4, 10, -10},
		{30, 24, 24, 22, 20, 18, 14, 16}
	};
	SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	for (row = 0; row < 8; row++)
	{
		for (col = 0; col < 8; col++)
		{
			point[row][col].x = col * len + offset;
			point[row][col].y = row * len + offset;
			point[row][col].z = zmatrix[row][col];
		}
	}

	for (row = 0; row < 8; row++)
	{
		for (col = 0; col < 8; col++)
		{
			tmp[row][col].x = inclination * (point[row][col].x - point[row][col].y) + offset;
			tmp[row][col].y = ((1 - inclination) * (point[row][col].x +  point[row][col].y ) + offset);
			tmp[row][col].z = 0;
			/*tmp[row][col].x = point[row][col].x;*/
			/*tmp[row][col].y = point[row][col].y;*/
			/*tmp[row][col].z = point[row][col].z;*/
		}
	}

	for (row = 0; row < 8; row++)
	{
		for (col = 0; col < 8; col++)
		{
			if (col + 1 < 8)
				SDL_RenderDrawLine(instance.renderer, tmp[row][col].x, tmp[row][col].y, tmp[row][col + 1].x, tmp[row][col].y); /* uL */
			if (row + 1 < 8)
				SDL_RenderDrawLine(instance.renderer, tmp[row][col].x, tmp[row][col].y, tmp[row][col].x, tmp[row + 1][col].y); /* uL */
		}
	}

	(void)m_len;

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

