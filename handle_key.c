/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:37:44 by akarahan          #+#    #+#             */
/*   Updated: 2022/02/14 11:40:55 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_key(int key)
{
	return (key == UP || key == DOWN || key == LEFT || key == RIGHT
		|| key == PLUS || key == MINUS || key == ZERO || key == Z_KEY
		|| key == X_KEY || key == KEY_1 || key == KEY_2 || key == KEY_3
		|| key == KEY_4 || key == KEY_5 || key == KEY_6 || key == I_KEY
		|| key == Q_KEY || key == W_KEY || key == E_KEY);
}

int	handle_key(int key, t_fdf *fdf)
{
	move_zoom_check(fdf, key);
	rot_check(fdf, key);
	proj_check(fdf, key);
	iso_check(fdf, key);
	if (key == I_KEY || key == Q_KEY || key == W_KEY || key == E_KEY)
	{
		default_pos(fdf);
		fdf->zoom = fdf->default_zoom;
	}
	if (key == Z_KEY)
		fdf->ch_height += 5;
	if (key == X_KEY)
		fdf->ch_height -= 5;
	if (is_key(key))
	{
		ft_bzero(fdf->img.addr, WIDTH * HEIGHT * (fdf->img.bpp / 8));
		draw_map(fdf);
	}
	if (key == ESC)
		close_app(fdf);
	return (0);
}
