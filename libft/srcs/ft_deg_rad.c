/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deg_rad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:41:13 by akarahan          #+#    #+#             */
/*   Updated: 2022/02/10 13:44:27 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_deg2rad(float deg)
{
	return (deg * (PI / 180));
}

float	ft_rad2deg(float rad)
{
	return (rad * (180 / PI));
}
