/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:46:00 by adespond          #+#    #+#             */
/*   Updated: 2016/03/15 13:19:12 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	error_arg(void)
{
	write(1, "Usage <filename> [mandelbrot/julia/burningship]\n", 48);
	exit(1);
}

void	error_malloc(void)
{
	write(1, "Malloc error\n", 13);
}
