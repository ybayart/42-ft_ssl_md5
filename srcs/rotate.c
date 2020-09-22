/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:07:32 by hexa              #+#    #+#             */
/*   Updated: 2020/09/22 12:04:16 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t	ft_left_rotate(uint32_t x, uint32_t n)
{
	return ((x << n) | (x >> (32 - n)));
}

uint32_t	ft_right_rotate(uint32_t x, uint32_t n)
{
	return ((x >> n) | (x << (32 - n)));
}

uint64_t	ft_right_rotate_64(uint64_t x, uint64_t n)
{
	return ((x >> n) | (x << (64 - n)));
}

uint64_t	ft_right_shift_64(uint64_t x, uint64_t n)
{
	return (x >> n);
}
