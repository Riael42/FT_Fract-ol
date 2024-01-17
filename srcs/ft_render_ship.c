/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_ship.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:29:33 by riael             #+#    #+#             */
/*   Updated: 2023/10/16 15:24:24 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	ft_render_ship(t_fract *fractal);

void	ft_ship_pixel(int x, int y, t_fract *fractal, int i)
{
	t_complex	z;
	t_complex	c;
	t_complex	n;
	double		color;

	z.x = 0;
	z.y = 0;
	c.x = ft_remap(x, 0, WINDOW_WIDTH) * fractal->zoom + fractal->shift_x;
	c.y = ft_remap(y, 0, WINDOW_HEIGHT) * fractal->zoom + fractal->shift_y;
	while (i < fractal->iterations_num)
	{
		n.x = fabs(z.x);
		n.y = fabs(z.y);
		z = sum_complex(square_complex(n), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = ft_color(i, BLACK, WHITE, 51);
			ft_pixie(x, y, &fractal->img, color);
			return ;
		}
		i += 1;
	}
	ft_pixie(x, y, &fractal->img, BLACK);
}

void	ft_render_ship(t_fract *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			ft_ship_pixel(x, y, fractal, 0);
			x += 1;
		}
		y += 1;
	}
	mlx_put_image_to_window(fractal->mlx_connection, \
							fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}
