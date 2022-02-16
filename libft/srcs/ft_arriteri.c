/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arriteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:37:26 by akarahan          #+#    #+#             */
/*   Updated: 2022/02/05 17:48:52 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arriteri(int **tab, void (*f)(int *, int), int factor)
{
	int	x;
	int	y;

	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[x])
		{
			(*f)(&tab[y][x], factor);
			++x;
		}
		++y;
	}
}
