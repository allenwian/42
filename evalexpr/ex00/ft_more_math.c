/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iallen <iallen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 19:16:59 by iallen            #+#    #+#             */
/*   Updated: 2017/07/16 21:42:46 by iallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_digit(char **str)
{
	if ((**str >= 48 && **str <= 57) ||
			(**str == '-' && (*(*str + 1) >= 48 && *(*str + 1) <= 57)))
		return (1);
	else
		return (0);
}

int	more_math(int val, char **str)
{
	while (**str && **str != '+' && **str != '-')
	{
		if (**str == ')')
			return (val);
		if (**str == '*' || **str == '%' || **str == '/')
		{
			val = math_two(val, str);
			continue;
		}
		(*str)++;
	}
	return (val);
}

int	math_one(int val, char **str)
{
	void	*func;

	if (**str == '+')
		func = &ft_add;
	if (**str == '-')
		func = &ft_subtract;
	(*str)++;
	while (**str)
	{
		if (check_digit(str) == 1)
			return (ft_math(val, more_math(ft_atoi(str), str), func));
		if (**str == '(')
		{
			(*str)++;
			return (ft_math(val, compute(str, 0, 0), func));
		}
		(*str)++;
	}
	return (42);
}

int	math_two(int val, char **str)
{
	int		(*func)(int, int);

	if (**str == '/')
		func = &ft_divide;
	if (**str == '*')
		func = &ft_multiply;
	if (**str == '%')
		func = &ft_modulus;
	(*str)++;
	while (**str)
	{
		if (check_digit(str) == 1)
			return (ft_math(val, ft_atoi(str), func));
		if (**str == '(')
		{
			(*str)++;
			return (ft_math(val, compute(str, 0, 0), func));
		}
		(*str)++;
	}
	return (42);
}
