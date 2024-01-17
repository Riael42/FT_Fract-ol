/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:32:23 by riael             #+#    #+#             */
/*   Updated: 2023/10/19 11:38:17 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysymdef.h>
# include <X11/keysym.h>
# include "../mlx-linux/mlx.h"
# include <complex.h>
# include <math.h>

# define WINDOW_WIDTH	800
# define WINDOW_HEIGHT	800
# define BLACK			0x000000 
# define WHITE			0xFFFFFF  
# define RED			0xFF0000  
# define GREEN			0x00FF00 
# define BLUE			0x0000FF 

//x is the real part
//y is the imaginary part

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_img
{
	void	*img_ptr;
	void	*pixel_ptr;
	int		bits_pixel;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_num; 
	double	shift_x; 
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		julia_shift;
	int		menu;
}				t_fract;

int				ft_ship(char **argv);
void			ft_shipmenu(t_fract *fractal);
int				mouse_handler(int butt, int x, int y, t_fract *fractal);
void			ft_ship_pixel(int x, int y, t_fract *fractal, int i);
void			ft_render_ship(t_fract *fractal);
void			ft_julmousemenu(t_fract *fractal);
void			ft_julforcedmenu(t_fract *fractal);
int				ft_track_julia(int x, int y, t_fract *fractal);
int				ft_skip_spaces(char *str);
void			ft_render_julia(t_fract *fractal);
int				ft_julia(char **argv);
void			ft_menu(int keysym, t_fract *fractal);
void			ft_putstr(char *str);
void			ft_start_menu(void);
int				ft_clubnova(char **argv);
void			ft_render_mathsishard(t_fract *fractal);
int				ft_mathsishard(char **argv);
void			ft_pixie(int x, int y, t_img *img, int color);
int				ft_strncmp(char *s1, char *s2, int n);
void			fractal_init(t_fract *fractal);
t_complex		sum_complex(t_complex z1, t_complex z2);
t_complex		square_complex(t_complex z);
int				ft_print_usage(void);
void			fractal_render(t_fract *fractal);
int				key_handler(int keysym, t_fract *fractal);
int				ft_fractol(int type, char **argv);
int				exit_handler(t_fract *fractal);
void			ft_render_clubnova(t_fract *fractal);
double			ft_atod(char *s, int i, int inte, double frac);
int				track_julia(int x, int y, t_fract *fractal);
void			ft_move_zoom(t_fract *fractal, int dir);
int				ft_mandelbrot(char **argv);
void			ft_init_events(t_fract *fractal);
void			ft_init_data(t_fract *fractal);
void			ft_report_incident(void);
void			ft_init_fract(t_fract *fractal);
void			ft_render_mandel(t_fract *fractal);
double			ft_remap(double old_value, double old_min, double old_max);
double			ft_color(double old_value, double new_min, \
				double new_max, double old_max);
void			ft_refresh_frac(t_fract *fractal);
t_complex		multiply_complex(t_complex z1, t_complex z2);
t_complex		div_complex(t_complex z1, t_complex z2);
t_complex		cub_complex(t_complex z);
t_complex		sub_complex(t_complex z1, t_complex z2);

#endif
