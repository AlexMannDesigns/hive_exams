#include "flood_fill.h"

void	flood_fill_algo(char **tab, t_point size, int col, int row, char empty)
{
	if (col < size.x
		&& row < size.y
		&& col >= 0
		&& row >= 0
		&& tab[row][col] == empty
		&& tab[row][col] != 'F')
		tab[row][col] = 'F';
	else
		return ;
	flood_fill_algo(tab, size, col + 1, row, empty);
	flood_fill_algo(tab, size, col - 1, row, empty);
	flood_fill_algo(tab, size, col, row + 1, empty);
	flood_fill_algo(tab, size, col, row - 1, empty);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	if (begin.x < 0 || begin.y < 0 || begin.x >= size.x || begin.y >= size.y || tab[begin.y][begin.x] == '\0')
		return ;
	flood_fill_algo(tab, size, begin.x, begin.y, tab[begin.y][begin.x]);
}
