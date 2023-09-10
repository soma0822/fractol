/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:17:36 by sinagaki          #+#    #+#             */
/*   Updated: 2023/06/16 20:52:14 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <float.h>

# define HEIGHT 600
# define WIDTH 600
# define JULIA 1
# define MANDELBROT 2

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	size;
	double	re;
	double	im;
	size_t	max;
}	t_data;

typedef struct s_complex{
	double	re;
	double	im;
}	t_complex;

void			draw_mandelbrot(t_data *data);
void			draw_julia(t_data *data);
t_complex		complex_add(t_complex a, t_complex b);
t_complex		complex_mul(t_complex a, t_complex b);
double			complex_abs(t_complex a);
int				av_checker(int as, char **av);
int				ft_strcmp(char *a, char *b);
void			error_julia(void);
void			ft_error(void);
void			mandelbrot_main(void);
int				close_window(void *param);
int				key_hook(int keycode, void *param);
int				mouse_hook(int keycode, int x, int y, void *param);
void			julia_main(double re, double im);
double			ft_atod(char *nbr, double integer, double decimal);
int				mouse_hook_mandebrot(int keycode, int x, int y, void *param);
unsigned int	catch_rgb(size_t n);

#endif