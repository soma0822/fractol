/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:34:47 by sinagaki          #+#    #+#             */
/*   Updated: 2023/06/16 16:39:56 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	exit(0);
	return (0);
}

int	key_hook(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		exit(0);
	}
	return (0);
}

int	main(int as, char **av)
{
	int		type;

	type = av_checker(as, av);
	if (type == JULIA)
		julia_main(ft_atod(av[2], 0, 0), ft_atod(av[3], 0, 0));
	if (type == MANDELBROT)
		mandelbrot_main();
	return (0);
}
