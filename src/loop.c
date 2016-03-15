/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:21:19 by adespond          #+#    #+#             */
/*   Updated: 2016/03/15 15:44:47 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		loop_hook(t_env *e)
{
	if (e->psychedelic == 1)
	{
		psychedelic(e);
		e->fractal(e);
	}
	if (e->zoom_auto == 1)
	{
		zoom_auto(e);
		e->fractal(e);
	}
	return (0);
}
