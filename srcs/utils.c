/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:07:32 by hexa              #+#    #+#             */
/*   Updated: 2020/09/15 11:52:35 by hexa             ###   ########.fr       */
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

uint32_t	ft_right_shift(uint32_t x, uint32_t n)
{
	return (x >> n);
}

uint32_t	sha256_makeword(uint32_t w[64], int j)
{
	uint32_t	s0;
	uint32_t	s1;

	s0 = (ft_right_rotate(w[j - 15], 7))
			^ (ft_right_rotate(w[j - 15], 18))
			^ (ft_right_shift(w[j - 15], 3));
	s1 = (ft_right_rotate(w[j - 2], 17))
			^ (ft_right_rotate(w[j - 2], 19))
			^ (ft_right_shift(w[j - 2], 10));
	return (w[j - 16] + s0 + w[j - 7] + s1);
}
