/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <hexanyn@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 07:40:50 by hexa              #+#    #+#             */
/*   Updated: 2020/09/28 20:29:38 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	(*g_fct[4])(t_sha1*) = {
	ft_sha1_fct_0, ft_sha1_fct_1, ft_sha1_fct_2, ft_sha1_fct_3
};

static void		prepare(int fd, t_sha1 *data)
{
	(*data).hash.fd = fd;
	(*data).h[0] = 0x67452301;
	(*data).h[1] = 0xefcdab89;
	(*data).h[2] = 0x98badcfe;
	(*data).h[3] = 0x10325476;
	(*data).h[4] = 0xc3d2e1f0;
	(*data).hash.i = 0;
	(*data).f = 0;
	(*data).k = 0;
	(*data).hash.blocks = 0;
	ft_bzero((*data).w, 80);
}

static void		work_one_block(t_sha1 *data)
{
	int			j;
	uint32_t	tmp;

	j = -1;
	while (++j < 16)
		ft_memrcpy((*data).w + j, (*data).buf + (j * 4), 4);
	j--;
	while (++j < 80)
		(*data).w[j] = sha1_makeword((*data).w, j);
	ft_memcpy((*data).m, (*data).h, 20);
	(*data).hash.i = 0;
	while ((*data).hash.i < 80)
	{
		g_fct[(*data).hash.i / 20](data);
		tmp = ft_left_rotate((*data).m[0], 5) + (*data).f + (*data).m[4] +
									(*data).k + (*data).w[(*data).hash.i++];
		(*data).m[4] = (*data).m[3];
		(*data).m[3] = (*data).m[2];
		(*data).m[2] = ft_left_rotate((*data).m[1], 30);
		(*data).m[1] = (*data).m[0];
		(*data).m[0] = tmp;
	}
	j = -1;
	while (++j < 5)
		(*data).h[j] += (*data).m[j];
}

static void		work(t_sha1 *data)
{
	size_t	i;

	i = 0;
	ft_bzero((*data).buf, 64);
	while (((*data).hash.len = get_next_buf((*data).hash.fd,
								(char*)(*data).buf, 64)) == 64)
	{
		work_one_block(data);
		ft_bzero((*data).buf, 64);
		i++;
	}
	padding(&((*data).buf), (64 * i) + (*data).hash.len, 64, ft_memrcpy);
	work_one_block(data);
	(*data).hash.blocks = i;
	if ((*data).hash.len > 55)
	{
		ft_bzero((*data).buf, 64);
		padding_size(&((*data).buf), (64 * i) + (*data).hash.len, 64,
																ft_memrcpy);
		work_one_block(data);
		(*data).hash.blocks++;
	}
}

char			ft_sha1(int fd, t_digest *digest)
{
	t_sha1	data;

	prepare(fd, &data);
	work(&data);
	if (data.hash.blocks == 0)
	{
		(*digest).text = ft_strdup((char*)data.buf);
		(*digest).len = data.hash.len;
	}
	if (!((*digest).ptr = ft_memalloc(20)))
		return (0);
	data.hash.i = 0;
	while (data.hash.i < 20)
	{
		((unsigned char*)(*digest).ptr)[data.hash.i] = (unsigned char)((data.h
				[data.hash.i >> 2] >> ((3 - (data.hash.i & 3)) * 8)) & 255);
		data.hash.i++;
	}
	(*digest).size = 40;
	return (1);
}
