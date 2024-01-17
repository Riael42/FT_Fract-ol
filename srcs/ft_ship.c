/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ship.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:09:58 by riael             #+#    #+#             */
/*   Updated: 2023/10/16 15:10:13 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	ft_ship(char **argv)
{
	t_fract	fractal;

	fractal.name = argv[1];
	fractal.julia_shift = 1;
	ft_init_fract(&fractal);
	fractal.julia_x = -0.835;
	fractal.julia_y = -0.2321;
	ft_render_ship(&fractal);
	mlx_loop(fractal.mlx_connection);
	return (42);
}
