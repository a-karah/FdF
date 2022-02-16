/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:37:51 by akarahan          #+#    #+#             */
/*   Updated: 2022/02/16 18:56:42 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;
	int		offset;

	if (!(x <= 0 || y <= 0 || x >= WIDTH || y >= HEIGHT))
	{
		offset = ((y * fdf->img.line_len) + (x * (fdf->img.bpp / 8)));
		dst = fdf->img.addr + offset;
		*(unsigned int *)dst = color;
	}
}

void	handle_window(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF");
	fdf->img.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bpp,
			&fdf->img.line_len, &fdf->img.endian);
	draw_map(fdf);
	mlx_hook(fdf->win, 2, 1L << 0, handle_key, fdf);
	mlx_hook(fdf->win, ON_DESTROY, 1L << 2, close_app, fdf);
	mlx_loop(fdf->mlx);
}
