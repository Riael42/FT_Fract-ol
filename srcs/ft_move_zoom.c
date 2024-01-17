/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_zoom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:44:18 by riael             #+#    #+#             */
/*   Updated: 2023/10/13 19:24:46 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	ft_move_zoom(t_fract *fractal, int dir)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(fractal->mlx_connection, fractal->mlx_window, &x, &y);
	if (y > (WINDOW_WIDTH / 2 + 100))
		fractal->shift_y += (0.1 * fractal->zoom);
	if (y < (WINDOW_WIDTH / 2 - 100))
		fractal->shift_y -= (0.1 * fractal->zoom);
	if (x > (WINDOW_HEIGHT / 2 + 100))
		fractal->shift_x += (0.1 * fractal->zoom);
	if (x < (WINDOW_HEIGHT / 2 - 100))
		fractal->shift_x -= (0.1 * fractal->zoom);
	if (x < (WINDOW_HEIGHT / 2 + 100) && \
		x > (WINDOW_HEIGHT / 2 - 100) && \
		y < (WINDOW_WIDTH / 2 + 100) && \
		y > (WINDOW_WIDTH / 2 - 100))
		fractal->zoom *= (dir == 0) * 0.95 + (dir != 0) * 1.05;
}
