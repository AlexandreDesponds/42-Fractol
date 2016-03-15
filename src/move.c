/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:25:53 by adespond          #+#    #+#             */
/*   Updated: 2016/03/15 13:09:52 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	zoom_in(t_env *e)
{
	e->x += e->win_width / 12;
	e->y += e->win_height / 12;
	e->z = e->z * 1.2;
	e->x = e->x * 1.2;
	e->y = e->y * 1.2;
}

void	zoom_out(t_env *e)
{
	if (e->z / 1.2 < 10)
		return ;
	e->x -= e->win_width / 12;
	e->y -= e->win_height / 12;
	e->z = e->z / 1.2;
	e->x = e->x / 1.2;
	e->y = e->y / 1.2;
}
