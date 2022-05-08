#include "flood_fill.h"
#include <stdio.h>
#include <stdlib.h>

char	**make_area(char *zone[], t_point size)
{
	char **area;
	int i, j;
		
	area = (char **) malloc(sizeof(char *) * size.y);
	i = 0;
	while (i < size.y)
	{
		area[i] = (char *) malloc((sizeof(char) * size.x) + sizeof(char));
		area[i][size.x] = '\0'; 
		j = 0;
		while (j < size.x)
		{
			area[i][j] = zone[i][j];
			j++;
		}
		i++;
	}
	return (area);
}

void	print_tab(char **area, t_point size)
{
	int i, j;

	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (area[i][j])
		{
			printf("%c ", area[i][j]);	
			j++;
		}
		printf("\n");
		i++;
	}
}

int main(void)
{
	char **area;
	t_point size = {8, 5};
	t_point begin = {0, 0};
	char *zone[] = {
		"11111100",
		"10001000",
		"10010000",
		"10110010",
		"11110000",
	};
	area = make_area(zone, size);
	print_tab(area, size);
	printf("\n");
	flood_fill(area, size, begin);
	print_tab(area, size);
	return (0);
}
