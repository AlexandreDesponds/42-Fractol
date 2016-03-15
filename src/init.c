/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 20:09:59 by adespond          #+#    #+#             */
/*   Updated: 2016/03/15 15:42:34 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static t_mandelbrot		*init_mandelbrot(void)
{
	t_mandelbrot	*m;

	m = (t_mandelbrot *)malloc(sizeof(t_mandelbrot));
	if (m == NULL)
		error_malloc();
	m->x1 = -2.1;
	m->x2 = 0.6;
	m->y1 = -1.2;
	m->y2 = 1.2;
	m->zr = 0;
	m->zi = 0;
	m->cr = 0;
	m->ci = 0;
	m->tmp = 0;
	return (m);
}

static t_mandelbrot		*init_julia(void)
{
	t_mandelbrot	*j;

	j = (t_mandelbrot *)malloc(sizeof(t_mandelbrot));
	if (j == NULL)
		error_malloc();
	j->x1 = -2.1;
	j->x2 = 0.6;
	j->y1 = -1.2;
	j->y2 = 1.2;
	j->zr = 0;
	j->zi = 0;
	j->cr = 0;
	j->ci = 0;
	j->tmp = 0;
	return (j);
}

t_env					*init_env(void)
{
	t_env	*e;

	e = (t_env *)malloc(sizeof(t_env));
	if (e == NULL)
		error_malloc();
	e->win_width = WIDTH;
	e->win_height = HEIGHT;
	e->x = 0;
	e->y = 0;
	e->z = 150;
	e->option_x = WIDTH / 2;
	e->option_y = HEIGHT / 2;
	e->color_max = 0x000000;
	e->mlx = mlx_init();
	e->i_max = 50;
	e->mouse_stop = 0;
	e->psychedelic = 0;
	e->color_value = 1;
	e->img = mlx_new_image(e->mlx, e->win_width, e->win_height);
	e->pxl = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->ed));
	e->mdb = init_mandelbrot();
	e->jul = init_julia();
	return (e);
}
