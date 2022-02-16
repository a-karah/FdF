/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:37:35 by akarahan          #+#    #+#             */
/*   Updated: 2022/02/11 22:14:14 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_error(void)
{
	ft_putstr_fd(strerror(errno), STDERR);
	ft_putchar_fd('\n', STDERR);
	exit(1);
}
