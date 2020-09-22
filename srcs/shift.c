/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 12:04:21 by hexa              #+#    #+#             */
/*   Updated: 2020/09/22 12:16:13 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t	ft_right_shift(uint32_t x, uint32_t n)
{
	return (x >> n);
}

uint32_t	ft_left_shift(uint32_t x, uint32_t n)
{
	return (x << n);
}
