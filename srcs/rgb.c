/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 20:24:10 by sinagaki          #+#    #+#             */
/*   Updated: 2023/06/16 20:52:43 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

unsigned int	catch_rgb(size_t n)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	r = (n % 16 * 16) << 16;
	g = (n % 8 * 32) << 8;
	b = (n % 32 * 8) << 0;
	return (r + g + b);
}
