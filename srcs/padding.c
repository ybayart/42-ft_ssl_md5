/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 10:53:21 by hexa              #+#    #+#             */
/*   Updated: 2020/09/15 18:39:27 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char		padding_simple(t_hash *data, size_t size, void *(*fct)(void *,
														const void *, size_t))
{
	(*data).dstlen = (*data).srclen + 1;
	(*data).blocks = (((*data).dstlen % size > (size * 0.875) ?
		(*data).dstlen + size : (*data).dstlen) / size) + 1;
	(*data).dstlen = (*data).blocks * size;
	if (((*data).dst = ft_memalloc((*data).dstlen)) == NULL)
		return (0);
	*(char*)((*data).dst + (*data).srclen) = (1 << 7);
	ft_memcpy((*data).dst, (*data).src, (*data).srclen);
	(*data).srclen *= 8;
	fct((*data).dst + ((*data).dstlen - (size / 8)), &((*data).srclen), (size / 8));
	return (1);
}
