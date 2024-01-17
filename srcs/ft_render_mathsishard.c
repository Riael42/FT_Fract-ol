/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_mathsishard.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:48:58 by riael             #+#    #+#             */
/*   Updated: 2023/10/13 21:21:18 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	ft_render_mathsishard(t_fract *fractal);

void	ft_maths_pixel(int x, int y, t_fract *fractal, int i)
{
	t_complex	z;
	t_complex	c;
	t_complex	n;
	t_complex	m;
	double		color;

	z.x = 1;
	z.y = 0;
	n.x = 2.9;
	m.x = -42;
	c.x = ft_remap(x, 0, WINDOW_WIDTH) * fractal->zoom + fractal->shift_x;
	c.y = ft_remap(y, 0, WINDOW_HEIGHT) * fractal->zoom + fractal->shift_y;
	while (i < fractal->iterations_num)
	{
		z = sub_complex(z, sum_complex(c, sub_complex(cub_complex(z), \
		div_complex(n, multiply_complex(square_complex(z), m)))));
		if ((z.x * z.x) + (z.y * z.y) > 3.5)
		{
			color = ft_color(i, BLACK, WHITE, 749);
			ft_pixie(x, y, &fractal->img, color);
			return ;
		}
		i += 1;
	}
	ft_pixie(x, y, &fractal->img, BLACK);
}

void	ft_render_mathsishard(t_fract *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			ft_maths_pixel(x, y, fractal, 0);
			x += 1;
		}
		y += 1;
	}
	mlx_put_image_to_window(fractal->mlx_connection, \
							fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}
