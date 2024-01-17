/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:19:59 by riael             #+#    #+#             */
/*   Updated: 2023/10/13 19:45:42 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

t_complex	multiply_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = (z1.x * z2.x) - (z1.y * z2.y);
	result.y = (z1.x * z2.y) + (z2.x * z1.y);
	return (result);
}
