/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 20:02:31 by adespond          #+#    #+#             */
/*   Updated: 2016/03/14 20:03:30 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		mouse_move_hook(int x, int y, t_env *e)
{
	if (x < 0 || x >= e->win_width || y < 0 || y >= e->win_height ||
			e->mouse_stop == 1)
		return (0);
	e->option_x = x;
	e->option_y = y;
	e->fractal(e);
	return (0);
}

int		mouse_click_hook(int k, int x, int y, t_env *e)
{
	if (k == MOUSE_ZOOM_IN)
	{
		e->x += x / 5;
		e->y += y / 5;
		e->z = e->z * 1.2;
		e->y = e->y * 1.2;
		e->x = e->x * 1.2;
	}
	if (k == MOUSE_ZOOM_OUT)
	{
		e->x -= x / 5;
		e->y -= y / 5;
		e->z = e->z / 1.2;
		e->y = e->y / 1.2;
		e->x = e->x / 1.2;
	}
	e->fractal(e);
	return (0);
}
