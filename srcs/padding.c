/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 10:53:21 by hexa              #+#    #+#             */
/*   Updated: 2020/09/26 03:07:59 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		padding(void *buf, size_t src, size_t size, void *(*fct)())
{
	size_t	dst;

	dst = src + 1;
	dst = (((dst % size > (size * 0.875) ?
		dst + size : dst) / size) + 1) * size;
	*((unsigned char*)buf + (src % size)) = (1 << 7);
	if (src % size < (size * 0.875))
	{
		if (size == 128)
			padding_size_128(buf, src, size, fct);
		else
			padding_size(buf, src, size, fct);
	}
}

void		padding_whirlpool(void *buf, size_t src)
{
	size_t	dst;

	dst = src + 1;
	dst = (((dst % 64 > 32 ?
		dst + 64 : dst) / 64) + 1) * 64;
	*((unsigned char*)buf + (src % 64)) = (1 << 7);
	if (src % 64 < 32 - 1)
		padding_size_whirlpool(buf, src);
}

void		padding_size(void *buf, size_t src, size_t size, void *(*fct)())
{
	src *= 8;
	fct(buf + (int)(size * 0.875), &(src), (size / 8));
}

void		padding_size_128(void *buf, __uint128_t src, size_t size,
															void *(*fct)())
{
	src *= 8;
	fct(buf + (int)(size * 0.875), &(src), (size / 8));
}

void		padding_size_whirlpool(void *buf, size_t src)
{
	int		low_bits[16];
	int		high_bits[16];
	int		bits;

	buf += 32;
	src *= 8;
	bits = 16;
	while (bits--)
	{
		low_bits[bits] = src % 256;
		src /= 256;
	}
	bits = 16;
	while (bits--)
	{
		high_bits[bits] = src % 256;
		src /= 256;
	}
	bits = -1;
	while (++bits < 16)
		*(char*)buf++ = high_bits[bits];
	bits = -1;
	while (++bits < 16)
		*(char*)buf++ = low_bits[bits];
}
