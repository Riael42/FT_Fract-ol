/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 23:41:01 by riael             #+#    #+#             */
/*   Updated: 2023/10/13 19:48:24 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	ft_julia(char **argv)
{
	t_fract	fractal;

	fractal.name = argv[1];
	if (argv[2] != (void *)0)
	{
		fractal.julia_x = ft_atod(argv[2], ft_skip_spaces(argv[2]), 0, 0);
	}
	else
		fractal.julia_x = -0.835;
	if (argv[3] != (void *)0)
	{
		fractal.julia_y = ft_atod(argv[3], ft_skip_spaces(argv[3]), 0, 0);
	}
	else
		fractal.julia_y = -0.2321;
	ft_init_fract(&fractal);
	ft_render_julia(&fractal);
	mlx_loop(fractal.mlx_connection);
	return (42);
}
