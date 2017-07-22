/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 15:05:19 by amatigno          #+#    #+#             */
/*   Updated: 2017/07/09 22:48:08 by mnila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"
#include "printing.h"

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
