/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:39:08 by sinagaki          #+#    #+#             */
/*   Updated: 2023/06/16 20:42:22 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	error_julia(void)
{
	write(1, "Please write\n\"./fractol julia x y\"\n-10 < x,y < 10\n", 50);
	exit (1);
}

void	ft_error(void)
{
	write(1, "List of avaible fractals:\n* mandelbrot\n* julia\n", 47);
	exit (1);
}
