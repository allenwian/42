/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 15:10:28 by amatigno          #+#    #+#             */
/*   Updated: 2017/07/09 16:16:35 by iallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

int			is_number_or_dot(int c);
int			is_valid(int ac, char **av);
int			check_row(char **board, int val, int row);
int			check_col(char **board, int val, int col);
int			check_square(char **board, int val, int r, int c);
int			check_all(char **board, int val, int row, int col);
int			backtrack(char **board, int val, int place);
int			is_valid_board(char **board, int r, int c);

#endif
