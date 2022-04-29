//function must accept **char arrary, t_point for dimensions, and t_point for starting point
//Fill the zone the start point is in, with char F
//Zones delimited horizontally and vertically by other characters OR array boundary

#include "flood_fill.h"

void	print_tab(char **tab, int y)
{
	int i = 0;
	while (i < y)
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

char	**make_area(char **tab, int y, int x)
{
	char 	**res;
	int	i;
	int	j;

	res = (char **)malloc(sizeof(char *) * y);
	while (i < y)
	{
		res[i] = (char *)malloc(sizeof(char) * x);
		j = 0;
		while (j < x)
		{
			res[i][j] = tab[i][j];	
			j++;
		}
		res[i][j] = '\0';	
		i++;
	}
	return res;
}

void	flood_fill_helper(char **tab, t_point size, char clr, int row, int col)
{
	if (row < 0 || col < 0 || col >= size.x || row >= size.y)
		return ;
	if (tab[row][col] == 'F' || tab[row][col] != clr)
		return ;
	tab[row][col] = 'F';
	flood_fill_helper(tab, size, clr, row + 1, col);
	flood_fill_helper(tab, size, clr, row - 1, col);
	flood_fill_helper(tab, size, clr, row, col + 1);
	flood_fill_helper(tab, size, clr, row, col - 1);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	clr;
	int	row;
	int	col;

	clr = tab[begin.y][begin.x];
	row = begin.y;
	col = begin.x;
	
	flood_fill_helper(tab, size, clr, row, col);
}

int main(void)
{
	char **area;
	t_point size = {8,5};
	t_point begin = {2, 3};
	char *zone[] = {
		"00001000",
		"00001000",
		"00001000",
		"00001000",
		"00001000",	
	};
	area = make_area(zone, size.y, size.x);
	print_tab(zone, size.y);
	flood_fill(area, size, begin);
	printf("\n");
	print_tab(area, size.y);
	return (0);
}
