/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 20:07:10 by adespond          #+#    #+#             */
/*   Updated: 2016/03/15 15:45:33 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	key_move(int k, t_env *e)
{
	if (k == KEY_DOWN)
		e->y += 100;
	if (k == KEY_UP)
		e->y -= 100;
	if (k == KEY_RIGHT)
		e->x += 100;
	if (k == KEY_LEFT)
		e->x -= 100;
}

static void	key_zoom(int k, t_env *e)
{
	if (k == KEY_ZOOM_IN)
		zoom_in(e);
	if (k == KEY_ZOOM_OUT)
		zoom_out(e);
}

static void	key_reset(int k, t_env *e)
{
	if (k == KEY_RESET)
	{
		e->x = 0;
		e->y = 0;
		e->z = 150;
		e->option_x = WIDTH / 2;
		e->option_y = HEIGHT / 2;
		e->color_max = 0x000000;
		e->i_max = 50;
		e->mouse_stop = 0;
		e->psychedelic = 0;
		e->color_value = 1;
	}
}

int			key_hook(int k, t_env *e)
{
	key_zoom(k, e);
	key_move(k, e);
	key_reset(k, e);
	if (k == KEY_DEEP_ADD)
		e->i_max += 10;
	if (k == KEY_DEEP_SUB)
		e->i_max -= 10;
	if (k == KEY_AUTO_ZOOM)
		e->zoom_auto = !e->zoom_auto;
	if (k == KEY_PSYCHEDELIC)
		e->psychedelic = !e->psychedelic;
	if (k == KEY_ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	if (k == KEY_MOUSE_STOP)
		e->mouse_stop = !e->mouse_stop;
	e->fractal(e);
	return (0);
}
