/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:12:03 by riael             #+#    #+#             */
/*   Updated: 2023/10/16 15:30:25 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	ft_julforcedmenu(t_fract *fractal);
void	ft_julmousemenu(t_fract *fractal);

void	ft_shipmenu(t_fract *fractal)
{
	ft_putstr("\n|Menu closed|\n");
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	fractal->name = "ship";
	fractal->julia_x = 0;
	fractal->julia_y = 0;
	ft_init_fract(fractal);
	ft_render_ship(fractal);
	mlx_loop(fractal->mlx_connection);
	return ;
}

void	ft_julmousemenu(t_fract *fractal)
{
	ft_putstr("\n|Menu closed|\n");
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	fractal->name = "julia";
	fractal->julia_x = 0;
	fractal->julia_y = 0;
	fractal->julia_shift = 1;
	ft_init_fract(fractal);
	ft_render_julia(fractal);
	mlx_loop(fractal->mlx_connection);
	return ;
}

void	ft_julforcedmenu(t_fract *fractal)
{
	ft_putstr("\n|Menu closed|\n");
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	ft_init_fract(fractal);
	fractal->name = "julia";
	fractal->julia_x = -0.8;
	fractal->julia_y = 0.156;
	fractal->julia_shift = 0;
	ft_render_julia(fractal);
	mlx_loop(fractal->mlx_connection);
	return ;
}
