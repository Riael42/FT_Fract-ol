/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clubnova.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:29:17 by riael             #+#    #+#             */
/*   Updated: 2023/10/13 19:15:28 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	ft_clubnova(char **argv)
{
	t_fract	fractal;

	fractal.name = argv[1];
	fractal.julia_shift = 1;
	ft_init_fract(&fractal);
	fractal.julia_x = -0.835;
	fractal.julia_y = -0.2321;
	ft_render_clubnova(&fractal);
	mlx_loop(fractal.mlx_connection);
	return (42);
}
