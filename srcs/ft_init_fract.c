/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:06:37 by riael             #+#    #+#             */
/*   Updated: 2023/10/13 21:02:55 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	ft_connectnt(void);
void	ft_windownt(t_fract *fractal);
void	ft_imgnt(t_fract *fractal);

void	ft_init_fract(t_fract *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == (void *)0)
		return (ft_connectnt());
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, \
										WINDOW_WIDTH, WINDOW_HEIGHT, \
										fractal->name);
	if (fractal->mlx_window == (void *)0)
		return (ft_windownt(fractal));
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, \
										WINDOW_WIDTH, WINDOW_HEIGHT);
	if (fractal->img.img_ptr == (void *)0)
		return (ft_imgnt(fractal));
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr, \
											&fractal->img.bits_pixel, \
											&fractal->img.line_len, \
											&fractal->img.endian);
	ft_init_events(fractal);
	ft_init_data(fractal);
}

void	ft_imgnt(t_fract *fractal)
{
	int	j;

	j = write(1, "|Failed to create fractimage|\n", 30);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	if (fractal->mlx_connection == (void *)0)
		j = write(1, "|You are getting alpha particle'd, do not resist|\n", 50);
	else
		free(fractal->mlx_connection);
	j += 1;
}

void	ft_windownt(t_fract *fractal)
{
	int	j;

	j = write(1, "|Failed to create MLX Window|\n", 30);
	mlx_destroy_display(fractal->mlx_connection);
	if (fractal->mlx_connection == (void *)0)
		j = write(1, "|You are getting alpha particle'd, do not resist|\n", 50);
	else
		free(fractal->mlx_connection);
	j += 1;
}

void	ft_connectnt(void)
{
	int	j;

	j = write(1, "|Failed to establish mlx connection!|\n", 38);
	j = write(1, "|This incident has now been reported|\n", 38);
	ft_report_incident();
	j += 1;
}
