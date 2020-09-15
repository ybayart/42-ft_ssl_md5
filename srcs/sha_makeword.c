/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_makeword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:49:54 by hexa              #+#    #+#             */
/*   Updated: 2020/09/15 17:50:03 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

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

uint64_t	sha512_makeword(uint64_t w[80], int j)
{
	uint64_t	s0;
	uint64_t	s1;

	s0 = (ft_right_rotate_64(w[j - 15], 1))
			^ (ft_right_rotate_64(w[j - 15], 8))
			^ (ft_right_shift_64(w[j - 15], 7));
	s1 = (ft_right_rotate_64(w[j - 2], 19))
			^ (ft_right_rotate_64(w[j - 2], 61))
			^ (ft_right_shift_64(w[j - 2], 6));
	return (w[j - 16] + s0 + w[j - 7] + s1);
}
