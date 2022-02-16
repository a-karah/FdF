/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:44:15 by akarahan          #+#    #+#             */
/*   Updated: 2022/02/14 11:44:16 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max_int(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

float	ft_max_float(float x, float y)
{
	if (x > y)
		return (x);
	return (y);
}
