/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:32:52 by riael             #+#    #+#             */
/*   Updated: 2023/10/13 19:49:25 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	ft_init_events(t_fract *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, \
			key_handler, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, \
			mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask, \
			exit_handler, fractal);
	mlx_hook(fractal->mlx_window, MotionNotify, PointerMotionMask, \
			ft_track_julia, fractal);
}
