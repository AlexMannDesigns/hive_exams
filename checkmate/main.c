/* 
Assignment name  : checkmate 
Expected files   : *.c, *.h
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program who takes rows of a chessboard in argument and check if your 
King is in a check position.

Chess is played on a chessboard, a squared board of 8-squares length with 
specific pieces on it : King, Queen, Bishop, Knight, Rook and Pawns.
For this exercice, you will only play with Pawns, Bishops, Rooks and Queen...
and obviously a King.

Each piece have a specific method of movement, and all patterns of capture are
detailled in the examples.txt file.

A piece can capture only the first ennemy piece it founds on its capture
patterns.

The board have a variable size but will remains a square. There's only one King
and all other pieces are against it. All other characters except those used for
pieces are considered as empty squares.

The King is considered as in a check position when an other enemy piece can
capture it. When it's the case, you will print "Success" on the standard output
followed by a newline, otherwise you will print "Fail" followed by a newline.

If there is no arguments, the program will only print a newline.

Examples:

$> ./chessmate '..' '.K' | cat -e
Fail$
$> ./chessmate 'R...' '..P.' '.K..' '....' | cat -e
Success$
$> ./chessmate 'R...' 'iheK' '....' 'jeiR' | cat -e
Success$
$> ./chessmate | cat -e
$
$>
*/
#include "checkmate.h"

void get_size(t_coords **res, char **av)
{
	int i = 0;

	while (av[0][i] != '\0')
		i++;
	(*res)->x = i;
	(*res)->y = i;
}

void get_king(t_coords **res, int ac, char **av)
{
	int i, j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == 'K')
			{
				(*res)->x = j;
				(*res)->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	t_coords *size, *king;

	if (ac > 1)
	{
		size =	(t_coords *) malloc(sizeof(t_coords)); 
		king =	(t_coords *) malloc(sizeof(t_coords)); 
		get_size(&size, av + 1);
		get_king(&king, ac, av + 1);
		if (puzzle_control(size, king, av + 1))
			write(1, "Success", 7);
		else
			write(1, "Fail", 4);
		free(size);
		free(king);
	}
	write(1, "\n", 1);
	return (0);
}



