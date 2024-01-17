/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 23:00:40 by riael             #+#    #+#             */
/*   Updated: 2023/10/19 11:39:11 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	ft_mandelmenu(t_fract *fractal);
void	ft_mathsmenu(t_fract *fractal);
void	ft_clubmenu(t_fract *fractal);
void	ft_infomenu(t_fract *fractal);

void	ft_menu(int keysym, t_fract *fractal)
{
	if (keysym == XK_1)
		ft_mandelmenu(fractal);
	if (keysym == XK_2)
		ft_mathsmenu(fractal);
	if (keysym == XK_3)
		ft_clubmenu(fractal);
	if (keysym == XK_4)
		ft_julmousemenu(fractal);
	if (keysym == XK_5)
		ft_julforcedmenu(fractal);
	if (keysym == XK_6)
		ft_shipmenu(fractal);
	if (keysym == XK_7)
		ft_infomenu(fractal);
}

void	ft_infomenu(t_fract *fractal)
{
	ft_putstr("\n|Keybindings|\n");
	ft_putstr("|----------------------------|\n");
	ft_putstr("|= key: increases the details|\n");
	ft_putstr("|- key: decreases the details|\n");
	ft_putstr("|Esc: start the menu, or exit|\n");
	ft_putstr("|z: sets zoom level to zero. |\n");
	ft_putstr("|Mouse wheel up: zoom in     |\n");
	ft_putstr("|Mouse wheel down: zoom out  |\n");
	ft_putstr("|X: locks/unlocks julia track|\n");
	ft_putstr("|Left click: Nothing.        |\n");
	ft_putstr("|Right click: Also nothing   |\n");
	ft_putstr("|----------------------------|\n");
	ft_putstr("|Menu closed|\n");
	fractal->menu = 0;
}

void	ft_mandelmenu(t_fract *fractal)
{
	ft_putstr("\n|Menu closed|\n");
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	fractal->name = "mandelbrot";
	ft_init_fract(fractal);
	ft_render_mandel(fractal);
	mlx_loop(fractal->mlx_connection);
	return ;
}

void	ft_mathsmenu(t_fract *fractal)
{
	ft_putstr("\n|Menu closed|\n");
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	fractal->name = "mathsishard";
	ft_init_fract(fractal);
	ft_render_mathsishard(fractal);
	mlx_loop(fractal->mlx_connection);
	return ;
}

void	ft_clubmenu(t_fract *fractal)
{
	ft_putstr("\n|Menu closed|\n");
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	fractal->name = "blotnova";
	fractal->julia_x = -0.8;
	fractal->julia_y = -0.2231;
	fractal->julia_shift = 1;
	ft_init_fract(fractal);
	ft_render_clubnova(fractal);
	mlx_loop(fractal->mlx_connection);
	return ;
}
