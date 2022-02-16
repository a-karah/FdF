/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:23:22 by akarahan          #+#    #+#             */
/*   Updated: 2022/02/13 19:29:38 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	percent(int start, int end, int curr)
{
	float	a;
	float	b;

	a = curr - start;
	b = end - start;
	if (!b)
		return (1.0);
	else
		return (a / b);
}

int	get_light(int clr1, int clr2, float perc)
{
	return ((int)(clr1 + (clr2 - clr1) * perc));
}

int	lerp(t_line *line, float x, float y)
{
	float	perc;
	int		r;
	int		g;
	int		b;

	if (line->clr_s == line->clr_e)
		return (line->clr_s);
	if (line->dx > line->dy)
		perc = percent(line->x_s, line->x1, x);
	else
		perc = percent(line->y_s, line->y1, y);
	r = get_light(get_r(line->clr_s), get_r(line->clr_e), perc);
	g = get_light(get_g(line->clr_s), get_g(line->clr_e), perc);
	b = get_light(get_b(line->clr_s), get_b(line->clr_e), perc);
	return (create_trgb(0, r, g, b));
}

int	get_z_clr(t_fdf *fdf, int z)
{
	float	perc;
	int		r;
	int		g;
	int		b;

	perc = percent(fdf->z_min, fdf->z_max, z);
	r = get_light(get_r(AYU_B), get_r(AYU_Y), perc);
	g = get_light(get_g(AYU_B), get_g(AYU_Y), perc);
	b = get_light(get_b(AYU_B), get_b(AYU_Y), perc);
	return (create_trgb(0, r, g, b));
}
