/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:39:52 by akarahan          #+#    #+#             */
/*   Updated: 2022/02/11 22:14:18 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_check(t_fdf *fdf, int key)
{
	if (key == KEY_1)
		fdf->alpha += ft_deg2rad(1);
	if (key == KEY_2)
		fdf->alpha -= ft_deg2rad(1);
	if (key == KEY_3)
		fdf->beta += ft_deg2rad(1);
	if (key == KEY_4)
		fdf->beta -= ft_deg2rad(1);
	if (key == KEY_5)
		fdf->gamma += ft_deg2rad(1);
	if (key == KEY_6)
		fdf->gamma -= ft_deg2rad(1);
}

void	move_zoom_check(t_fdf *fdf, int key)
{
	if (key == UP)
		fdf->shift_y -= 10;
	if (key == DOWN)
		fdf->shift_y += 10;
	if (key == LEFT)
		fdf->shift_x -= 10;
	if (key == RIGHT)
		fdf->shift_x += 10;
	if (key == PLUS)
		fdf->zoom += 5;
	if (key == MINUS && (fdf->zoom - 5) != 0)
		fdf->zoom -= 5;
	if (key == ZERO)
	{
		fdf->zoom = fdf->default_zoom;
		fdf->ch_height = 0;
		fdf->proj = 1;
		fdf->alpha = 0;
		fdf->beta = 0;
		fdf->gamma = 0;
		fdf->angle = ft_deg2rad(30);
	}
}

void	proj_check(t_fdf *fdf, int key)
{
	if (key == Q_KEY)
		fdf->proj = 2;
	if (key == W_KEY)
		fdf->proj = 3;
	if (key == E_KEY)
		fdf->proj = 4;
}

void	iso_check(t_fdf *fdf, int key)
{
	if (key == I_KEY)
		fdf->proj = 1;
}
