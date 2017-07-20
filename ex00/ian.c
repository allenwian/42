/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ian.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iallen <iallen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 20:51:47 by iallen            #+#    #+#             */
/*   Updated: 2017/07/09 00:46:58 by iallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_row(char **board, int val, int row)
{
	int col;

	col = 0;
	while (col < 9)
	{
		if (board[row][col] == val)
			return (0);
		col++;
	}
	return (1);
}

int		check_col(char **board, int val, int col)
{
	int row;

	row = 0;
	while (row < 9)
	{
		if (board[row][col] == val)
			return (0);
		row++;
	}
	return (1);
}

int		check_square(char **board, int val, int r, int c)
{
	int	row;
	int col;
	int pR;
	int pC;

	pR = r / 3 + 1;
	pC = c / 3 + 1; 
	row = (pR - 1) * 3;
	col = (pC - 1) * 3;
	while (row < pR * 3)
	{
		while (col < pC * 3)
		{
			if (board[row][col] == val)
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

int		check_all(char **board, int val, int row, int col)
{
	if (check_row(board, val, row) == 0 || check_col(board, val, col) == 0 
			|| check_square(board, val, row, col) == 0)
		return (0);
	return (1);
}

int		backtrack(char **board, int val, int place)
{
	int r;
	int c;

	r = place / 9;
	c = place % 9;
	if (board[r][c] != 46)
	{
		if (place == 80)
			return (1);
		return (backtrack(board, val, place + 1));
	}
	if (place == 80)
	{
		while (val < 10)
		{
			if (check_all(board, val + 48, r, c) == 1)
			{
				board[r][c] = val + 48;
				return (1);
			}
			val++;
		}
	}
	else 
	{
		while (val < 10)
		{
			if (check_all(board, val + 48, r, c) == 1)
			{
				board[r][c] = val + 48;
				if (backtrack(board, 1, place + 1) == 1)
					return (1);
			}
			val++;
		}
		board[r][c] = 46;
		return (0);
	}
	return (0);
}

void	print_board(char **board)
{
	int r;
	int c;

	r = 0;
	c = 0;
	while (r < 9)
	{
		c = 0;
		while (c < 9)
		{
			write(1, &board[r][c], 1);
			if (c != 8)
				write(1, " ", 1);
			c++;
		}
		write(1, "\n", 1);
		r++;
	}
}

int		main(int argc, char **argv)
{
	argv = argv + 1;
	backtrack(argv, 1, 0);
	print_board(argv);
	return (0);
}
