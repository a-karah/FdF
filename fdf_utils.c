/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:40:07 by akarahan          #+#    #+#             */
/*   Updated: 2022/02/14 10:59:47 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	default_pos(t_fdf *fdf)
{
	fdf->shift_x = WIDTH / 2 - ((fdf->width / 2) * fdf->zoom);
	fdf->shift_y = HEIGHT / 2 - ((fdf->width / 2) * fdf->zoom);
}

void	default_zoom(t_fdf *fdf)
{
	while (WIDTH < fdf->width * fdf->zoom)
		fdf->zoom /= 1.1;
	fdf->default_zoom = fdf->zoom;
}

void	init_fdf(t_fdf *fdf)
{
	fdf->zoom = 20;
	default_zoom(fdf);
	default_pos(fdf);
	find_min_max(fdf);
	fdf->angle = ft_deg2rad(30);
	fdf->alpha = 0;
	fdf->beta = 0;
	fdf->gamma = 0;
	fdf->ch_height = 0;
	fdf->proj = 1;
}

int	close_app(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (fdf->tab[i])
	{
		free(fdf->tab[i]);
		++i;
	}
	free(fdf->tab);
	if (fdf->img.img)
		mlx_destroy_image(fdf->mlx, fdf->img.img);
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	free(fdf->mlx);
	free(fdf);
	exit(0);
	return (0);
}
