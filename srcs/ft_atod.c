/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:12:57 by riael             #+#    #+#             */
/*   Updated: 2023/09/22 21:02:20 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

double	ft_atod(char *s, int i, int inte, double frac)
{
	int		sign;
	double	powe;

	sign = 1;
	powe = 1;
	while (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		i += 1;
	}
	while (s[i] != '.' && s[i] != '\0')
	{
		inte = (inte * 10) + (s[i] - '0');
		i += 1;
	}
	if (s[i] == '.')
		i += 1;
	while (s[i] != '\0')
	{
		powe /= 10;
		frac = frac + (s[i] - 48) * powe;
		i += 1;
	}
	return ((inte + frac) * sign);
}
