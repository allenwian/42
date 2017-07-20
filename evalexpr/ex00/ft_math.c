/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iallen <iallen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 23:20:47 by iallen            #+#    #+#             */
/*   Updated: 2017/07/18 19:48:24 by iallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_atoi(char **str)
{
	int ne;
	int all;

	ne = 1;
	all = 0;
	while (**str && **str < 33)
		(*str)++;
	if (**str == 45 || **str == 43)
	{
		ne = (**str == 45 ? -1 : 1);
		(*str)++;
	}
	while (**str)
	{
		if (**str > 57 || **str < 48)
			return (ne * all);
		else
			all = all * 10 + **str - 48;
		(*str)++;
	}
	all = ne * all;
	return (all);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb / 10 == 0)
	{
		if (nb < 0)
		{
			ft_putchar(45);
			ft_putchar((-1 * (nb % 10 - 10)) % 10 + 48);
		}
		else
			ft_putchar(nb + 48);
	}
	else
	{
		ft_putnbr(nb / 10);
		if (nb < 0)
			ft_putchar((-1 * (nb % 10 - 10)) % 10 + 48);
		else
			ft_putchar(nb % 10 + 48);
	}
}

int		ft_math(int first, int second, int (*f)(int, int))
{
	return (f(first, second));
}
