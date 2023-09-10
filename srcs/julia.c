/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:13:27 by sinagaki          #+#    #+#             */
/*   Updated: 2023/06/16 20:59:00 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

size_t	julia(double x, double y, t_data *data)
{
	t_complex	c;
	t_complex	z;
	size_t		i;

	z.re = x;
	z.im = y;
	c.re = data->re;
	c.im = data->im;
	i = 0;
	while (i < data->max && complex_abs(z) < 4)
	{
		z = complex_add(complex_mul(z, z), c);
		i++;
	}
	return (i);
}

void	draw_julia(t_data *data)
{
	double	x;
	double	y;
	size_t	n;
	int		pixel_offset;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			n = julia(x * data->size / WIDTH - data->size / 2,
					y * data->size / HEIGHT - data->size / 2, data);
			pixel_offset = (x * (data->bits_per_pixel / 8))
				+ (y * data->line_length);
			*(unsigned int *)(data->addr + pixel_offset) = catch_rgb(n);
			y++;
		}
		x++;
	}
}

void	julia_main(double re, double im)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "window");
	data.img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img_ptr,
			&(data.bits_per_pixel), &(data.line_length), &(data.endian));
	data.size = 4;
	data.max = 1000;
	data.re = re;
	data.im = im;
	draw_julia(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	mlx_hook(data.win_ptr, 17, 0, close_window, &data);
	mlx_hook(data.win_ptr, 2, 0, key_hook, &data);
	mlx_hook(data.win_ptr, 4, 0, mouse_hook, &data);
	mlx_loop(data.mlx_ptr);
}
