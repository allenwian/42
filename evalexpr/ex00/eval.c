/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iallen <iallen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 11:58:05 by iallen            #+#    #+#             */
/*   Updated: 2017/07/16 21:38:32 by iallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		find_temp(char **str, int temp)
{
	if (**str == '(')
	{
		(*str)++;
		temp = compute(str, 0, 0);
	}
	if (check_digit(str) == 1)
	{
		temp = ft_atoi(str);
	}
	if (**str == '*' || **str == '%' || **str == '/')
	{
		temp = math_two(temp, str);
	}
	return (temp);
}

int		compute(char **str, int result, int temp)
{
	while (**str)
	{
		if (**str == ')')
		{
			result += temp;
			(*str)++;
			return (result);
		}
		temp = find_temp(str, temp);
		if (**str == '+' || **str == '-')
		{
			result = result + temp;
			temp = 0;
			result = math_one(result, str);
			continue;
		}
		if (**str)
			(*str)++;
	}
	result = result + temp;
	return (result);
}

int		eval_expr(char *str)
{
	return (compute(&str, 0, 0));
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
