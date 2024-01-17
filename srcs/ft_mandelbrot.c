/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:00:04 by riael             #+#    #+#             */
/*   Updated: 2023/09/22 20:56:43 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	ft_mandelbrot(char **argv)
{
	t_fract	fractal;

	fractal.name = argv[1];
	ft_init_fract(&fractal);
	ft_render_mandel(&fractal);
	mlx_loop(fractal.mlx_connection);
	return (42);
}
