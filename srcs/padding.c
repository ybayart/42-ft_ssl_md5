/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 10:53:21 by hexa              #+#    #+#             */
/*   Updated: 2020/09/16 13:55:39 by hexa             ###   ########.fr       */
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
	if (src % size < (size * 0.875) - 1)
	{
		if (size == 128)
			padding_size_128(buf, src, size, fct);
		else
			padding_size(buf, src, size, fct);
	}
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
