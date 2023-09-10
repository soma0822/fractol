/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:45:41 by sinagaki          #+#    #+#             */
/*   Updated: 2023/06/16 15:20:29 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	ans;

	ans.re = a.re + b.re;
	ans.im = a.im + b.im;
	return (ans);
}

t_complex	complex_mul(t_complex a, t_complex b)
{
	t_complex	ans;

	ans.re = a.re * b.re - a.im * b.im;
	ans.im = a.re * b.im + a.im * b.re;
	return (ans);
}

double	complex_abs(t_complex a)
{
	return (a.re * a.re + a.im * a.im);
}
