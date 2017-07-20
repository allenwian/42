/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iallen <iallen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 21:47:49 by iallen            #+#    #+#             */
/*   Updated: 2017/07/16 21:40:55 by iallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

int		find_temp(char **str, int temp);

int		check_digit(char **str);

int		more_math(int val, char **str);

int		math_one(int val, char **str);

int		math_two(int val, char **str);

int		compute(char **str, int result, int temp);

int		eval_expr(char *str);

int		ft_add(int first, int second);

int		ft_subtract(int first, int second);

int		ft_divide(int first, int second);

int		ft_modulus(int first, int second);

int		ft_multiply(int first, int second);

int		ft_math(int first, int second, int (*f)(int, int));

void	ft_putchar(char c);

void	ft_putnbr(int nb);

int		ft_atoi(char **str);

#endif
