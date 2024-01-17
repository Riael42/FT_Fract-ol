/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:55:29 by riael             #+#    #+#             */
/*   Updated: 2023/10/16 15:10:59 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	ft_fractol(int type, char **argv)
{
	if (type == 0)
		return (ft_mandelbrot(argv));
	if (type == 1)
		return (ft_clubnova(argv));
	if (type == 2)
		return (ft_mathsishard(argv));
	if (type == 3)
		return (ft_julia(argv));
	if (type == 4)
		return (ft_julia(argv));
	if (type == 5)
		return (ft_ship(argv));
	return (42);
}
