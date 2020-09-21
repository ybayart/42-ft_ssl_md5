/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whirlpool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <hexanyn@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 07:40:50 by hexa              #+#    #+#             */
/*   Updated: 2020/09/21 21:33:16 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint8_t			g_rc[256];

static void		prepare(int fd, t_whirlpool *data)
{
	(*data).hash.fd = fd;
	(*data).hash.i = 0;
	ft_bzero((*data).h, 64);
	ft_bzero((*data).w, 64);
	ft_bzero((*data).k, 64);
}

static void		work_calc(t_whirlpool *data)
{
	(void)g_rc;
	ft_whirlpool_sub_bytes((*data).k);
	ft_whirlpool_shift_cols((*data).k);
	ft_whirlpool_mix_rows((*data).k);
	ft_memxor((*data).k, g_rc + ((*data).hash.i * 8), 8);
	ft_whirlpool_sub_bytes((*data).w);
	ft_whirlpool_shift_cols((*data).w);
	ft_whirlpool_mix_rows((*data).w);
	ft_memxor((*data).w, (*data).k, 64);
}

static void		work_one_block(t_whirlpool *data)
{
	ft_memcpy((*data).w, (*data).buf, 64);
	ft_memcpy((*data).k, (*data).h, 64);
	ft_memxor((*data).w, (*data).k, 64);
	(*data).hash.i = 0;
	while ((*data).hash.i < ROUND_WHIRL)
	{
		work_calc(data);
		(*data).hash.i++;
	}
	ft_memxor((*data).w, (*data).buf, 64);
	ft_memxor((*data).h, (*data).w, 64);
}

static void		work(t_whirlpool *data)
{
	size_t	i;

	i = 0;
	ft_bzero((*data).buf, 64);
	while (((*data).hash.len = read((*data).hash.fd, (*data).buf, 64)) == 64)
	{
		work_one_block(data);
		ft_bzero((*data).buf, 64);
		i++;
	}
	padding_whirlpool(&((*data).buf), (64 * i) + (*data).hash.len);
	work_one_block(data);
	(*data).hash.blocks = i;
	if ((*data).hash.len > 31)
	{
		ft_bzero((*data).buf, 64);
		padding_size_whirlpool(&((*data).buf), (64 * i) + (*data).hash.len);
		work_one_block(data);
		(*data).hash.blocks++;
	}
}

char			ft_whirlpool(int fd, t_digest *digest)
{
	t_whirlpool		data;

	prepare(fd, &data);
	work(&data);
	if (data.hash.blocks == 0)
	{
		(*digest).text = ft_strdup((char*)data.buf);
		(*digest).len = data.hash.len;
	}
	if (!((*digest).ptr = ft_memalloc(128)))
		return (0);
	data.hash.i = 0;
	while (data.hash.i < 8)
	{
		ft_memcpy((*digest).ptr + (data.hash.i * 8),
								&(data.h[data.hash.i]), 8);
		data.hash.i++;
	}
	(*digest).size = 128;
	return (1);
}
