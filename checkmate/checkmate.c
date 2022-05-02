#include "checkmate.h"

static int blocked(char c)
{
	if (c == 'B' || c == 'Q' || c == 'P' || c == 'R')
		return (1);
	return (0);
}

static int check_pawn(t_coords *king, int y, int x)
{
	if (y + 1 == king->y && (x - 1 == king->x || x + 1 == king->x))
		return (1);
	return (0);
}

static int check_bishop(int size, char **board, int y, int x)
{
	int factor, blk1, blk2, blk3, blk4;

	factor = 1;
	blk1 = blk2 = blk3 = blk4 = 0;
	while (factor < size)
	{
		if (!blk1 && x + factor < size && y + factor < size) 
		{	
			if (board[y + factor][x + factor] == 'K')
				return (1);
			if (blocked(board[y + factor][x + factor]))
				blk1 = 1;
		}
		if (!blk2 && x - factor >= 0 && y + factor < size)
		{
			if (board[y + factor][x - factor] == 'K')
				return (1);
			if (blocked(board[y + factor][x - factor]))
				blk2 = 1;
		}
		if (!blk3 && x + factor < size && y - factor >= 0)
		{
			if (board[y - factor][x + factor] == 'K')
				return (1);
			if (blocked(board[y - factor][x + factor]))
				blk3 = 1;
		}
		if (!blk4 && x + factor < size && y - factor >= 0)
		{
			if (board[y - factor][x - factor] == 'K')
				return (1);
			if (blocked(board[y - factor][x - factor]))
				blk4 = 1;
		}
		factor++;
	}
	return (0);
}

static int check_rook(int size, char **board, int y, int x)
{
	int factor, blk1, blk2, blk3, blk4;

	factor = 1;
	blk1 = blk2 = blk3 = blk4 = 0;
	while (factor < size)
	{
		if (!blk1 && x + factor < size)
		{
			if (board[y][x + factor] == 'K')
				return (1);
			if (blocked(board[y][x + factor]))
				blk1 = 1;
		}
		if (!blk2 && x - factor >= 0)
		{
			if (board[y][x - factor] == 'K')
				return (1);
			if (blocked(board[y][x - factor]))
				blk2 = 1;
		}
		if (!blk3 && y - factor >= 0)
		{
			if (board[y - factor][x] == 'K')
				return (1);
			if (blocked(board[y - factor][x]))
				blk3 = 1;
		}
		if (!blk4 && y + factor < size)
		{
			if (board[y + factor][x] == 'K')
				return (1);
			if (blocked(board[y + factor][x]))
				blk4 = 1;
		}
		factor++;
	}
	return (0);
}

int puzzle_control(t_coords *size, t_coords *king, char **av)
{
	int i, j;

	i = 0;
	while (i < size->y)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == 'P')
			{
				if (check_pawn(king, i, j))
					return (1);
			}
			if (av[i][j] == 'B')
			{
				if (check_bishop(size->y, av, i, j))
					return (1);
			}
			if (av[i][j] == 'R')
			{
				if (check_rook(size->y, av, i, j))	
					return (1);			
			}
			if (av[i][j] == 'Q')
			{
				if (check_rook(size->y, av, i, j) || check_bishop(size->y, av, i, j))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
