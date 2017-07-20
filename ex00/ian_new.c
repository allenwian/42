/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ian_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 12:48:43 by amatigno          #+#    #+#             */
/*   Updated: 2017/07/09 15:53:09 by iallen           ###   ########.fr       */
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
		col = (pC - 1) * 3;
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
	else
	{
		while (val < 10)
		{
			if (check_all(board, val + 48, r, c) == 1)
			{
				board[r][c] = val + 48;
				if (place == 80 || backtrack(board, 1, place + 1) == 1)
					return (1);
				board[r][c] = '.';
			}
			val++;
		}
		board[r][c] = 46;
		return (0);
	}
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

char	*ft_strchr(char *s, int c)
{
	while (*s != (char)c && *s != '\0')
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

int is_number_or_dot(int c)
{
	int i;

	i = c;
	if (47 < i && i < 58)
		return (1);
	if (i == 46)
		return (1);
	return (0);

}

int	is_valid(int ac, char **av)
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

	while (r < 9)
	{
		c = 0;
		while (c < 9)
		{
			if (board[r][c] != '.')
			{
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
	return (1);
}

int		main(int argc, char **argv)
{
	argv = argv + 1;
	if (!is_valid(argc, argv))
	{
		write(1, "Error\n", 6);	
		return (0);
	}
	if (is_valid_board(argv, 0, 0) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	backtrack(argv, 1, 0);
	print_board(argv);
	return (0);
}
