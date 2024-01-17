/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:45:28 by riael             #+#    #+#             */
/*   Updated: 2023/10/13 19:45:34 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

t_complex	div_complex(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.x = (z1.x * z2.x + z1.y * z2.y) / (z2.x * z2.x + z2.y * z2.y);
	res.y = (z1.y * z2.x - z1.x * z2.y) / (z2.x * z2.x + z2.y * z2.y);
	return (res);
}

t_complex	cub_complex(t_complex z)
{
	t_complex	res;

	res = multiply_complex(square_complex(z), z);
	return (res);
}

t_complex	sub_complex(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.x = z1.x - z2.x;
	res.y = z1.y - z2.y;
	return (res);
}
