/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:38:13 by akarahan          #+#    #+#             */
/*   Updated: 2022/02/11 22:14:05 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	parse_row(int *tab, char *line)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
	{
		tab[i] = ft_atoi(split[i]);
		free(split[i]);
		++i;
	}
	free(split);
}

static void	parse_to_arr(t_fdf *fdf, char *fname)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fdf->tab = (int **)malloc(sizeof(int *) * (fdf->height + 1));
	while (i < fdf->height)
		fdf->tab[i++] = (int *)malloc(sizeof(int) * (fdf->width + 1));
	fd = open(fname, O_RDONLY);
	if (fd < 0)
		handle_error();
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		parse_row(fdf->tab[i], line);
		free(line);
		line = get_next_line(fd);
		++i;
	}
	close(fd);
	fdf->tab[i] = NULL;
}

void	parse_map(t_fdf *fdf, char *fname)
{
	char	*line;
	int		fd;

	fdf->height = 0;
	fdf->width = 0;
	fd = open(fname, O_RDONLY);
	if (fd < 0)
		handle_error();
	line = get_next_line(fd);
	fdf->width = ft_count_words(line, ' ');
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		++fdf->height;
	}
	close(fd);
	parse_to_arr(fdf, fname);
}
