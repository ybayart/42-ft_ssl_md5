/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <hexanyn@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 07:40:50 by hexa              #+#    #+#             */
/*   Updated: 2020/09/15 11:17:54 by hexa             ###   ########.fr       */
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

static void		prepare(char *str, size_t len, t_md5 *data)
{
	prepare_hash(str, len, &((*data).hash));
	(*data).h[0] = 0x67452301;
	(*data).h[1] = 0xefcdab89;
	(*data).h[2] = 0x98badcfe;
	(*data).h[3] = 0x10325476;
	(*data).i = 0;
	while ((*data).i < 16)
		(*data).w[(*data).i++] = (uint32_t)0;
	(*data).i = 0;
	(*data).f = 0;
	(*data).g = 0;
	while ((*data).i < 64)
	{
		g_k[(*data).i] = (uint32_t)floor(4294967296 * fabs(sin((*data).i + 1)));
		(*data).i++;
	}
	(*data).i = 0;
}

static void		work_calc(t_md5 *data)
{
	(*data).i = 0;
	while ((*data).i < 64)
	{
		g_fct[(*data).i / 16](data);
		(*data).f += (*data).m[0] + g_k[(*data).i] + (*data).w[(*data).g];
		(*data).m[0] = (*data).m[3];
		(*data).m[3] = (*data).m[2];
		(*data).m[2] = (*data).m[1];
		(*data).m[1] += ft_left_rotate((*data).f, g_s[(*data).i]);
		(*data).i++;
	}
}

static void		work(t_md5 *data)
{
	size_t	i;
	int		j;

	i = 0;
	while (i < (*data).hash.blocks)
	{
		j = -1;
		while (++j < 16)
			ft_memcpy((*data).w + j, (*data).hash.dst + (i * 64) + (j * 4), 4);
		j = -1;
		while (++j < 4)
			(*data).m[j] = (*data).h[j];
		work_calc(data);
		j = -1;
		while (++j < 4)
			(*data).h[j] += (*data).m[j];
		i++;
	}
}

unsigned char	*ft_md5(char *str, size_t len)
{
	t_md5			data;
	unsigned char	*digest;

	prepare(str, len, &data);
	if (padding_simple(&(data.hash), (512 / 8), ft_memcpy) == 0)
		return (NULL);
	work(&data);
	if (!(digest = ft_memalloc(32)))
	{
		free(data.hash.dst);
		return (NULL);
	}
	ft_memmove(digest, &(data.h[0]), 4);
	ft_memmove(digest + 4, &(data.h[1]), 4);
	ft_memmove(digest + 8, &(data.h[2]), 4);
	ft_memmove(digest + 12, &(data.h[3]), 4);
	free(data.hash.dst);
	return (digest);
}
