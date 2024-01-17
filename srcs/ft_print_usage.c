/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_usage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:48:39 by riael             #+#    #+#             */
/*   Updated: 2023/10/16 15:26:50 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	ft_print_usage(void)
{
	int	j;

	j = write(1, "|Please try again! Proper usage:        |\n", 42);
	j = write(1, "|./fractol julia                        |\n", 42);
	j = write(1, "|./fractol julia realpart imaginarypart |\n", 42);
	j = write(1, "|./fractol mandelbrot                   |\n", 42);
	j = write(1, "|./fractol blotnova                     |\n", 42);
	j = write(1, "|./fractol mathsishard                  |\n", 42);
	j = write(1, "|./fractol ship                         |\n", 42);
	j = write(1, "|Thank you!                             |\n", 42);
	return (j);
}
