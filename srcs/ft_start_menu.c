/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 23:00:14 by riael             #+#    #+#             */
/*   Updated: 2023/10/16 15:28:28 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	ft_start_menu(void)
{
	ft_putstr("\n|Main menu|\n");
	ft_putstr("|Please press any of the keys|\n");
	ft_putstr("|----------------------------|\n");
	ft_putstr("|Esc: escape from the fractol|\n");
	ft_putstr("|Enter: return to the program|\n");
	ft_putstr("|1: start the mandlebrot set.|\n");
	ft_putstr("|2: start mathsishard fractal|\n");
	ft_putstr("|3: start the blot-nova fract|\n");
	ft_putstr("|4: start a julia set (mouse)|\n");
	ft_putstr("|5: start a preset julia set.|\n");
	ft_putstr("|6: start a burning ship set.|\n");
	ft_putstr("|7: show list of keybindings.|\n");
	ft_putstr("|----------------------------|");
}
