/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_julia.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 23:42:41 by riael             #+#    #+#             */
/*   Updated: 2023/09/22 23:47:23 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	ft_render_mandel(t_fract *fractal);

void	ft_julia_pixel(int x, int y, t_fract *fractal, int i)
{
	t_complex	z;
	t_complex	c;
	int			color;

	z.x = ft_remap(x, 0, WINDOW_WIDTH) * fractal->zoom + fractal->shift_x;
	z.y = ft_remap(y, 0, WINDOW_HEIGHT) * fractal->zoom + fractal->shift_y;
	c.x = fractal->julia_x;
	c.y = fractal->julia_y;
	while (i < fractal->iterations_num)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = ft_color(i, BLACK, WHITE, fractal->iterations_num);
			ft_pixie(x, y, &fractal->img, color);
			return ;
		}
		i += 1;
	}
	ft_pixie(x, y, &fractal->img, BLACK);
}

void	ft_render_julia(t_fract *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			ft_julia_pixel(x, y, fractal, 0);
			x += 1;
		}
		y += 1;
	}
	mlx_put_image_to_window(fractal->mlx_connection, \
							fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}
