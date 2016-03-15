/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:21:52 by adespond          #+#    #+#             */
/*   Updated: 2016/03/15 15:56:35 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRACTOL_H
# define __FRACTOL_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>

# define MOUSE_ZOOM_IN 5
# define MOUSE_ZOOM_OUT 4
# define KEY_ZOOM_IN 69
# define KEY_ZOOM_OUT 78
# define KEY_ESC 53
# define KEY_MOUSE_STOP 49
# define KEY_PSYCHEDELIC 19
# define KEY_AUTO_ZOOM 18
# define KEY_DEEP_ADD 116
# define KEY_DEEP_SUB 121
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_RESET 15
# define WIDTH 600
# define HEIGHT 400
# define PTR_MOTION_MASK (1L<<6)
# define MOTION_NOTIFY 6

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	int					win_height;
	int					win_width;
	intmax_t			x;
	intmax_t			y;
	intmax_t			z;
	int					option_x;
	int					option_y;
	int					mouse_stop;
	unsigned int		color_max;
	int					color_value;
	void				*img;
	char				*pxl;
	int					bpp;
	int					s_line;
	int					ed;
	int					zoom_auto;
	int					psychedelic;
	void				(*fractal)();
	int					i_max;
	struct s_mandelbrot	*mdb;
	struct s_mandelbrot	*jul;
}						t_env;

typedef struct			s_mandelbrot
{
	long double			x1;
	long double			x2;
	long double			y1;
	long double			y2;
	long double			zr;
	long double			zi;
	long double			cr;
	long double			ci;
	long double			tmp;
}						t_mandelbrot;

t_env					*init_env();
int						expose_hook(t_env *e);
int						key_hook(int k, t_env *e);
int						mouse_move_hook(int x, int y, t_env *e);
int						mouse_click_hook(int k, int x, int y, t_env *e);
void					put_info(t_env *e);
int						loop_hook(t_env *e);
void					zoom_auto(t_env *e);
void					zoom_in(t_env *e);
void					zoom_out(t_env *e);
void					put_pxl(t_env *e, int x, int y, unsigned int color);
void					mandelbrot(t_env *e);
void					julia(t_env *e);
void					burningship(t_env *e);
unsigned int			get_color(int i, t_env *e);
void					error_arg(void);
void					error_malloc(void);
void					psychedelic(t_env *e);
#endif
