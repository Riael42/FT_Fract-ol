/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_clubnova.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:29:33 by riael             #+#    #+#             */
/*   Updated: 2023/10/13 19:41:38 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	ft_render_clubnova(t_fract *fractal);

void	ft_nova_pixel(int x, int y, t_fract *fractal, int i)
{
	t_complex	z;
	t_complex	c;
	t_complex	n;
	t_complex	m;
	double		color;

	z.x = 1;
	z.y = 0;
	n.x = 1;
	m.x = 3;
	c.x = ft_remap(x, 0, WINDOW_WIDTH) * fractal->zoom + fractal->shift_x;
	c.y = ft_remap(y, 0, WINDOW_HEIGHT) * fractal->zoom + fractal->shift_y;
	while (i < fractal->iterations_num)
	{
		z = sum_complex(c, sub_complex(z, div_complex(sub_complex(\
		cub_complex(z), n), multiply_complex(square_complex(z), m))));
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = ft_color(i, BLACK, WHITE, fractal->iterations_num);
			ft_pixie(x, y, &fractal->img, color);
			return ;
		}
		i += 1;
	}
	ft_pixie(x, y, &fractal->img, BLACK);
}

void	ft_render_clubnova(t_fract *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			ft_nova_pixel(x, y, fractal, 0);
			x += 1;
		}
		y += 1;
	}
	mlx_put_image_to_window(fractal->mlx_connection, \
							fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}
