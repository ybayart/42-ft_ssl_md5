/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <hexanyn@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 07:40:50 by hexa              #+#    #+#             */
/*   Updated: 2020/09/26 02:38:59 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	(*g_fct[4])(t_md5*) = {
	ft_md5_fct_0, ft_md5_fct_1, ft_md5_fct_2, ft_md5_fct_3
};

static uint32_t g_k[64];

static int g_s[64] = {
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21,
};

static void		prepare(int fd, t_md5 *data)
{
	(*data).hash.fd = fd;
	(*data).h[0] = 0x67452301;
	(*data).h[1] = 0xefcdab89;
	(*data).h[2] = 0x98badcfe;
	(*data).h[3] = 0x10325476;
	(*data).hash.i = 0;
	while ((*data).hash.i < 16)
		(*data).w[(*data).hash.i++] = (uint32_t)0;
	(*data).hash.i = 0;
	(*data).f = 0;
	(*data).g = 0;
	(*data).hash.blocks = 0;
	while ((*data).hash.i < 64)
	{
		g_k[(*data).hash.i] = (uint32_t)floor(4294967296 *
								fabs(sin((*data).hash.i + 1)));
		(*data).hash.i++;
	}
	(*data).hash.i = 0;
}

static void		work_one_block(t_md5 *data)
{
	int		j;

	j = -1;
	while (++j < 16)
		ft_memcpy((*data).w + j, (*data).buf + (j * 4), 4);
	j = -1;
	while (++j < 4)
		(*data).m[j] = (*data).h[j];
	(*data).hash.i = 0;
	while ((*data).hash.i < 64)
	{
		g_fct[(*data).hash.i / 16](data);
		(*data).f += (*data).m[0] + g_k[(*data).hash.i] + (*data).w[(*data).g];
		(*data).m[0] = (*data).m[3];
		(*data).m[3] = (*data).m[2];
		(*data).m[2] = (*data).m[1];
		(*data).m[1] += ft_left_rotate((*data).f, g_s[(*data).hash.i]);
		(*data).hash.i++;
	}
	j = -1;
	while (++j < 4)
		(*data).h[j] += (*data).m[j];
}

static void		work(t_md5 *data)
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
	padding(&((*data).buf), (64 * i) + (*data).hash.len, 64, ft_memcpy);
	work_one_block(data);
	(*data).hash.blocks = i;
	if ((*data).hash.len > 55)
	{
		ft_bzero((*data).buf, 64);
		padding_size(&((*data).buf), (64 * i) + (*data).hash.len, 64,
																ft_memcpy);
		work_one_block(data);
		(*data).hash.blocks++;
	}
}

char			ft_md5(int fd, t_digest *digest)
{
	t_md5	data;

	prepare(fd, &data);
	work(&data);
	if (data.hash.blocks == 0)
	{
		(*digest).text = ft_strdup((char*)data.buf);
		(*digest).len = data.hash.len;
	}
	if (!((*digest).ptr = ft_memalloc(32)))
		return (0);
	data.hash.i = 0;
	while (data.hash.i < 4)
	{
		ft_memcpy((*digest).ptr + (data.hash.i * 4),
								&(data.h[data.hash.i]), 4);
		data.hash.i++;
	}
	(*digest).size = 32;
	return (1);
}
