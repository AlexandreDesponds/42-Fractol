/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 20:09:39 by adespond          #+#    #+#             */
/*   Updated: 2016/03/15 15:45:20 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	print_config(void)
{
	write(1, "------------------------------\n", 31);
	write(1, "MOVE  : up down left right    \n", 31);
	write(1, "ZOOM  : + - (numeric)         \n", 31);
	write(1, "DEEP  : pageup pagedown       \n", 31);
	write(1, "RESET : r                     \n", 31);
	write(1, "PSYCHADELIC MODE : 2          \n", 31);
	write(1, "AUTO ZOOM : 1                 \n", 31);
	write(1, "------------------------------\n", 31);
}

int		main(int argc, char **argv)
{
	t_env	*e;

	e = init_env();
	if (argc != 2)
		error_arg();
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		e->fractal = mandelbrot;
	if (ft_strcmp(argv[1], "julia") == 0)
		e->fractal = julia;
	if (ft_strcmp(argv[1], "burningship") == 0)
		e->fractal = burningship;
	if (e->fractal == NULL)
		error_arg();
	e->win = mlx_new_window(e->mlx, e->win_width, e->win_height,
			"Fract'ol adespond@42");
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_hook(e->win, MOTION_NOTIFY, PTR_MOTION_MASK, mouse_move_hook, e);
	mlx_mouse_hook(e->win, mouse_click_hook, e);
	mlx_loop_hook(e->mlx, loop_hook, e);
	print_config();
	e->fractal(e);
	mlx_loop(e->mlx);
	return (0);
}
