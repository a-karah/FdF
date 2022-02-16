/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:36:30 by akarahan          #+#    #+#             */
/*   Updated: 2022/02/14 11:04:28 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	proj_choice(t_fdf *fdf, float *x, float *y, int *z)
{
	if (fdf->proj == 1)
		isometric(x, y, *z, fdf);
	if (fdf->proj == 2)
	{
		*x = *y;
		*y = -*z;
	}
	if (fdf->proj == 3)
		*y = -*z;
}

void	init_line(t_fdf *fdf, t_line *line)
{
	zoom_xyz(fdf, line);
	rotate_xyz(fdf, &line->x, &line->y, &line->z);
	rotate_xyz(fdf, &line->x1, &line->y1, &line->z1);
	proj_choice(fdf, &line->x, &line->y, &line->z);
	proj_choice(fdf, &line->x1, &line->y1, &line->z1);
	move_xyz(fdf, line);
}

void	dda(t_fdf *fdf, t_line line)
{
	float	max;

	line.z = fdf->tab[(int)line.y][(int)line.x];
	line.z1 = fdf->tab[(int)line.y1][(int)line.x1];
	line.clr_s = get_z_clr(fdf, line.z);
	line.clr_e = get_z_clr(fdf, line.z1);
	init_line(fdf, &line);
	line.dx = line.x1 - line.x;
	line.dy = line.y1 - line.y;
	max = ft_max_float(ft_abs_float(line.dx), ft_abs_float(line.dy));
	line.dx /= max;
	line.dy /= max;
	line.x_s = line.x;
	line.y_s = line.y;
	while ((int)(line.x - line.x1) || (int)(line.y - line.y1))
	{
		fdf->color = lerp(&line, line.x, line.y);
		my_pixel_put(fdf, line.x, line.y, fdf->color);
		line.x += line.dx;
		line.y += line.dy;
	}
}

void	draw_map(t_fdf *fdf)
{
	t_line	line;
	int		x;
	int		y;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			line.x = x;
			line.y = y;
			line.x1 = x + 1;
			line.y1 = y;
			if (line.x < fdf->width - 1)
				dda(fdf, line);
			line.x1 = x;
			line.y1 = y + 1;
			if (line.y < fdf->height - 1)
				dda(fdf, line);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
}

// void	bresenham(t_fdf *fdf, t_line line)
// {
// 	int		dx;
// 	int		dy;
// 	int		P;
// 	int		y_step;
// 	int		z;
// 	int		z1;
// 	char	steep;

// 	zoom_xyz(fdf, &line);
// 	rotate_xyz(fdf, &line.x, &line.y, &line.z);
// 	rotate_xyz(fdf, &line.x1, &line.y1, &line.z1);
// 	proj_choice(&line.x, &line.y, &line.z, fdf);
// 	proj_choice(&line.x1, &line.y1, &line.z1, fdf);
// 	move_xyz(fdf, &line);
// 	dx = ft_abs_int(line.x1 - line.x);
// 	dy = ft_abs_int(line.y1 - line.y);
// 	steep = dy > dx;
// 	if (steep)
// 	{
// 		ft_swap_int(&line.x, &line.y);
// 		ft_swap_int(&line.x1, &line.y1);
// 		dx = ft_abs_int(line.x1 - line.x);
// 		dy = ft_abs_int(line.y1 - line.y);
// 	}
// 	if (line.x > line.x1)
// 	{
// 		ft_swap_int(&line.x, &line.x1);
// 		ft_swap_int(&line.y, &line.y1);
// 	}
// 	y_step = line.y1 > line.y ? 1 : -1;
// 	P = 2 * dy - dx;
// 	while (line.x <= line.x1)
// 	{
// 		if (steep)
// 			my_pixel_put(fdf, line.y, line.x, fdf->color);
// 		else
// 			my_pixel_put(fdf, line.x, line.y, fdf->color);
// 		if (P < 0)
// 			P += 2 * dy;
// 		else
// 		{
// 			P += 2*dy - 2*dx;
// 			line.y += y_step;
// 		}
// 		++line.x;
// 	}
// }
