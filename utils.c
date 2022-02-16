/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:38:26 by akarahan          #+#    #+#             */
/*   Updated: 2022/02/14 11:01:50 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_arr(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			ft_printf("%3d", fdf->tab[i][j]);
			++j;
		}
		ft_putchar_fd('\n', STDOUT);
		++i;
	}
}

void	find_min_max(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	fdf->z_max = INT_MIN;
	fdf->z_min = INT_MAX;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (fdf->z_max < fdf->tab[y][x])
				fdf->z_max = fdf->tab[y][x];
			if (fdf->z_min > fdf->tab[y][x])
				fdf->z_min = fdf->tab[y][x];
			++x;
		}
		++y;
	}
}
