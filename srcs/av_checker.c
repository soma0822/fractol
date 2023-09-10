/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:27:55 by sinagaki          #+#    #+#             */
/*   Updated: 2023/06/16 16:39:28 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	julia_av_check(char *nbr)
{
	double	i;
	int		flag;

	i = 1;
	flag = 1;
	if (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			flag = -1;
		nbr++;
	}
	if (*nbr == '\0')
		error_julia();
	while (*nbr >= '0' && *nbr <= '9')
		nbr++;
	if (*nbr == '.')
	{
		nbr++;
		if (*nbr == '\0')
			error_julia();
	}
	while (*nbr >= '0' && *nbr <= '9')
		nbr++;
	if (*nbr != '\0')
		error_julia();
}

int	av_checker(int as, char **av)
{
	if (as == 1)
		ft_error();
	if (ft_strcmp(av[1], "julia") == 0)
	{
		if (as != 4)
			error_julia();
		julia_av_check(av[2]);
		julia_av_check(av[3]);
		return (JULIA);
	}
	else if (ft_strcmp(av[1], "mandelbrot") == 0)
	{
		if (as != 2)
			ft_error();
		return (MANDELBROT);
	}
	else
	{
		ft_error();
	}
	return (0);
}
