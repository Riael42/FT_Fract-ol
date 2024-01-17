/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:21:53 by riael             #+#    #+#             */
/*   Updated: 2023/09/22 20:26:24 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

double	ft_color(double old_value, double new_min, \
				double new_max, double old_max)
{
	return ((new_max - new_min) * old_value / old_max + new_min);
}
