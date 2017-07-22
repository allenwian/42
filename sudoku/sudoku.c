/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 15:07:28 by amatigno          #+#    #+#             */
/*   Updated: 2017/07/09 22:53:33 by mnila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"
#include "printing.h"

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
	int p_row;
	int p_col;

	p_row = r / 3 + 1;
	p_col = c / 3 + 1;
	row = (p_row - 1) * 3;
	col = (p_col - 1) * 3;
	while (row < p_row * 3)
	{
		col = (p_col - 1) * 3;
		while (col < p_col * 3)
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
	while (val < 10)
	{
		if (check_all(board, val + 48, r, c) == 1)
		{
			board[r][c] = val + 48;
			if (place == 80 || backtrack(board, 1, place + 1) == 1)
				return (1);
		}
		val++;
	}
	board[r][c] = 46;
	return (0);
}
