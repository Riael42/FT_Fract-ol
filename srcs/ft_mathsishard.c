/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mathsishard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:55:07 by riael             #+#    #+#             */
/*   Updated: 2023/09/22 21:55:26 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	ft_mathsishard(char **argv)
{
	t_fract	fractal;

	fractal.name = argv[1];
	ft_init_fract(&fractal);
	ft_render_mathsishard(&fractal);
	mlx_loop(fractal.mlx_connection);
	return (42);
}
