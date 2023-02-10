/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:40:01 by akarahan          #+#    #+#             */
/*   Updated: 2023/02/10 15:03:22 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, int z, t_fdf *fdf)
{
	float	tmp_x;
	float	tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	*x = (tmp_x - tmp_y) * cos(fdf->angle);
	*y = (tmp_x + tmp_y) * sin(fdf->angle) - z;
}

void	zoom_xyz(t_fdf *fdf, t_line *line)
{
	line->x *= fdf->zoom;
	line->y *= fdf->zoom;
	if (line->z != 0)
		line->z = line->z * fdf->zoom - fdf->ch_height;
	line->x1 *= fdf->zoom;
	line->y1 *= fdf->zoom;
	if (line->z1 != 0)
		line->z1 = line->z1 * fdf->zoom - fdf->ch_height;
}

void	rotate_xyz(t_fdf *fdf, float *x, float *y, int *z)
{
	float	tmp_x;
	float	tmp_y;
	float	tmp_z;

	tmp_x = *x;
	tmp_y = *y;
	tmp_z = *z;
	*y = tmp_y * cos(fdf->alpha) + tmp_z * sin(fdf->alpha);
	*z = (int)(-tmp_y * sin(fdf->alpha) + tmp_z * cos(fdf->alpha));
	tmp_z = *z;
	*x = tmp_x * cos(fdf->beta) + tmp_z * sin(fdf->beta);
	*z = (int)(-tmp_x * sin(fdf->beta) + tmp_z * cos(fdf->beta));
	tmp_x = *x;
	tmp_y = *y;
	*x = tmp_x * cos(fdf->gamma) - tmp_y * sin(fdf->gamma);
	*y = tmp_x * sin(fdf->gamma) + tmp_y * cos(fdf->gamma);
}

void	move_xyz(t_fdf *fdf, t_line *line)
{
	line->x += fdf->shift_x;
	line->y += fdf->shift_y;
	line->x1 += fdf->shift_x;
	line->y1 += fdf->shift_y;
}
