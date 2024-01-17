/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:16:44 by riael             #+#    #+#             */
/*   Updated: 2023/10/16 15:10:44 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
			i = ft_fractol(0, argv);
		if (ft_strncmp(argv[1], "blotnova", 8) == 0)
			i = ft_fractol(1, argv);
		if (ft_strncmp(argv[1], "mathsishard", 11) == 0)
			i = ft_fractol(2, argv);
		if (ft_strncmp(argv[1], "julia", 5) == 0)
			i = ft_fractol(3, argv);
		if (ft_strncmp(argv[1], "ship", 4) == 0)
			i = ft_fractol(5, argv);
	}
	else if (argc == 4)
	{
		if (ft_strncmp(argv[1], "julia", 5) == 0)
			i = ft_fractol(4, argv);
	}
	if (i == 0)
		return (ft_print_usage());
	return (0);
}
