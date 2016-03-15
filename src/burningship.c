/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:41:57 by adespond          #+#    #+#             */
/*   Updated: 2016/03/15 13:13:40 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	burningship_iter(t_env *e)
{
	int		i;

	i = -1;
	while (++i < e->i_max)
	{
		e->mdb->tmp = e->mdb->zr;
		e->mdb->zr = e->mdb->zr * e->mdb->zr - e->mdb->zi * e->mdb->zi +
			e->mdb->cr;
		e->mdb->zi = 2 * fabsl(e->mdb->zi * e->mdb->tmp) + e->mdb->ci;
		if (e->mdb->zr * e->mdb->zr + e->mdb->zi * e->mdb->zi >= 4)
			return (i);
	}
	return (i);
}

void		burningship(t_env *e)
{
	intmax_t	x;
	intmax_t	y;

	x = e->x;
	while (++x < e->win_width + e->x)
	{
		y = e->y;
		while (++y < e->win_height + e->y)
		{
			e->mdb->zr = 0;
			e->mdb->zi = 0;
			e->mdb->cr = (long double)x / e->z + e->mdb->x1;
			e->mdb->ci = (long double)y / e->z + e->mdb->y1;
			put_pxl(e, x - e->x, y - e->y, get_color(burningship_iter(e), e));
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	put_info(e);
}
