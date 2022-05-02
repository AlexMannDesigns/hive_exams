#ifndef CHECKMATE_H

#define CHECKMATE_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_coords
{
	int	x;
	int	y;
}		t_coords;

int puzzle_control(t_coords *size, t_coords *king, char **av);

#endif
