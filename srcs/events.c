/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:27:28 by riael             #+#    #+#             */
/*   Updated: 2023/10/16 15:30:18 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	key_handler(int keysym, t_fract *fractal);
int	mouse_handler(int butt, int x, int y, t_fract *fractal);

int	exit_handler(t_fract *fractal)
{
	int	j;

	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	if (fractal->mlx_connection == (void *)0)
		j = write(1, "|You are getting alpha particle'd, do not resist|\n", 50);
	else
		free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
	j += 1;
	return (0);
}

int	mouse_handler(int butt, int x, int y, t_fract *fractal)
{
	(void)x;
	(void)y;
	if (butt == Button4)
	{
		ft_move_zoom(fractal, 0);
		fractal->zoom *= 0.95;
	}
	if (butt == Button5)
	{
		ft_move_zoom(fractal, 1);
		fractal->zoom *= 1.05;
	}
	ft_refresh_frac(fractal);
	return (0);
}

void	ft_simple_keys(int keysym, t_fract *fractal)
{
	if (keysym == XK_equal)
		fractal->iterations_num += 5;
	if (keysym == XK_minus)
		fractal->iterations_num -= 5;
	if (keysym == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);
	if (keysym == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom);
	if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);
	if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);
	if (keysym == XK_x)
		fractal->julia_shift = (fractal->julia_shift == 0);
	if (keysym == XK_z)
		fractal->zoom = 1.0;
}

int	key_handler(int keysym, t_fract *fractal)
{
	if (fractal->menu == 1 && keysym == XK_Return)
	{
		ft_putstr("\n|Menu closed|\n");
		fractal->menu = 0;
	}
	if (keysym == XK_Escape)
	{
		if (fractal->menu == 0)
		{
			fractal->menu = 1;
			ft_start_menu();
			return (0);
		}
		else
			exit_handler(fractal);
	}
	if (fractal->menu == 0)
		ft_simple_keys(keysym, fractal);
	if (fractal->menu == 1)
		ft_menu(keysym, fractal);
	ft_refresh_frac(fractal);
	return (0);
}
