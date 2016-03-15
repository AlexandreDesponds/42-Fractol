/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:39:23 by adespond          #+#    #+#             */
/*   Updated: 2016/03/15 15:44:29 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void			psychedelic(t_env *e)
{
	e->color_max += 10000;
	if (e->color_max >= 0xffffff)
		e->color_max = 0x000000;
	e->color_value += 1;
}

unsigned int	get_color(int a, t_env *e)
{
	unsigned int	c;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (a == e->i_max)
		return (e->color_max);
	r = (a * 5) * e->color_value;
	g = (255 - (a * 10)) * e->color_value;
	b = (255 - (a * 2)) * e->color_value;
	c = (r << 16) + (g << 8) + b;
	return (c);
}
