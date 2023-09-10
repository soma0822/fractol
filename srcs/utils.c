/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:37:29 by sinagaki          #+#    #+#             */
/*   Updated: 2023/06/16 20:39:41 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_strcmp(char *a, char *b)
{
	while (*a || *b)
	{
		if (*a != *b)
			return (1);
		a++;
		b++;
	}
	return (0);
}

double	ft_atod_decimal(char *nbr, double decimal)
{
	double	i;

	i = 1;
	while (*nbr >= '0' && *nbr <= '9')
	{
		i *= 0.1;
		decimal += (*nbr - '0') * i;
		nbr++;
	}
	return (decimal);
}

double	ft_atod(char *nbr, double integer, double decimal)
{
	double	i;
	double	flag;

	i = 1;
	flag = 1;
	if (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			flag = -1;
		nbr++;
	}
	while (*nbr >= '0' && *nbr <= '9')
	{
		integer = integer * 10 + *nbr++ - '0';
		if (integer >= 10)
			error_julia();
	}
	if (*nbr == '.')
		nbr++;
	decimal = ft_atod_decimal(nbr, decimal);
	return (flag * (integer + decimal));
}
