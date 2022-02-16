/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:38:01 by akarahan          #+#    #+#             */
/*   Updated: 2022/02/14 11:22:14 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_fdf	*fdf;

	if (argc != 2)
	{
		ft_printf("Yanlis arguman sayisi, kullanma sekli ./fdf <harita>.fdf\n");
		return (0);
	}
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	parse_map(fdf, argv[1]);
	init_fdf(fdf);
	handle_window(fdf);
	close_app(fdf);
	return (0);
}
