/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:39:02 by sinagaki          #+#    #+#             */
/*   Updated: 2023/06/16 20:55:39 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mouse_hook_mandebrot(int keycode, int x, int y, void *param)
{
	t_data	*data;

	x = 0;
	y = 0;
	data = (t_data *)param;
	if (keycode == 4)
	{
		data->size *= 1.1;
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw_mandelbrot(data);
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img_ptr, 0, 0);
	}
	if (keycode == 5)
	{
		data->size /= 1.1;
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw_mandelbrot(data);
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img_ptr, 0, 0);
	}
	return (0);
}
