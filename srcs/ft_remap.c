/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:03:05 by riael             #+#    #+#             */
/*   Updated: 2023/09/22 21:15:41 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

double	ft_remap(double old_value, double old_min, double old_max)
{
	double	a;
	double	b;
	double	c;

	a = 4.0;
	b = old_value - old_min;
	c = old_max - old_min;
	return (a * b / c - 2.0);
}
