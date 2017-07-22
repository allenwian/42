/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 15:06:32 by amatigno          #+#    #+#             */
/*   Updated: 2017/07/09 22:55:35 by mnila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		is_number_or_dot(int c)
{
	int i;

	i = c;
	if (48 < i && i < 58)
		return (1);
	if (i == 46)
		return (1);
	return (0);
}

int		is_valid(int ac, char **av)
{
	int i;
	int j;

	i = 0;
	if (ac != 10)
		return (0);
	while (i < ac - 1)
	{
		j = 0;
		while (av[i][j] && is_number_or_dot(av[i][j]))
			j++;
		if (j != 9)
			return (0);
		i++;
	}
	return (1);
}

int		is_valid_board(char **board, int r, int c)
{
	char	temp;
	int		counter;

	counter = 0;
	while (r < 9)
	{
		c = 0;
		while (c < 9)
		{
			if (board[r][c] != '.')
			{
				counter++;
				temp = board[r][c];
				board[r][c] = '.';
				if (check_all(board, temp, r, c) == 0)
					return (0);
				board[r][c] = temp;
			}
			c++;
		}
		r++;
	}
	if (counter < 17)
		return (0);
	return (1);
}
