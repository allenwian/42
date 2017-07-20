/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iallen <iallen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 22:59:27 by iallen            #+#    #+#             */
/*   Updated: 2017/07/16 21:40:15 by iallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_add(int first, int second)
{
	return (first + second);
}

int	ft_subtract(int first, int second)
{
	return (first - second);
}

int	ft_divide(int first, int second)
{
	if (second == 0)
		return (0);
	return (first / second);
}

int	ft_multiply(int first, int second)
{
	return (first * second);
}

int	ft_modulus(int first, int second)
{
	if (second == 0)
		return (0);
	return (first % second);
}
