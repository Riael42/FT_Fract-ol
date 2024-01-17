/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh_frac.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:45:07 by riael             #+#    #+#             */
/*   Updated: 2023/10/16 15:13:05 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	ft_refresh_frac(t_fract *fractal)
{
	if (ft_strncmp(fractal->name, "mandelbrot", 10) == 0)
		ft_render_mandel(fractal);
	if (ft_strncmp(fractal->name, "mathsishard", 11) == 0)
		ft_render_mathsishard(fractal);
	if (ft_strncmp(fractal->name, "blotnova", 8) == 0)
		ft_render_clubnova(fractal);
	if (ft_strncmp(fractal->name, "julia", 5) == 0)
		ft_render_julia(fractal);
	if (ft_strncmp(fractal->name, "ship", 4) == 0)
		ft_render_ship(fractal);
}
