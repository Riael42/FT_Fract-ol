/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_track_julia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:40:18 by riael             #+#    #+#             */
/*   Updated: 2023/10/13 20:54:40 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	ft_track_julia(int x, int y, t_fract *fractal)
{
	if (ft_strncmp(fractal->name, "julia", 5) == 0 \
		&& fractal->julia_shift == 1)
	{
		fractal->julia_x = ft_remap(x, 0, WINDOW_WIDTH) * \
			fractal->zoom + fractal->shift_x;
		fractal->julia_y = ft_remap(y, 0, WINDOW_HEIGHT) * \
			fractal->zoom + fractal->shift_y;
		ft_render_julia(fractal);
	}
	return (0);
}
