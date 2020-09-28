/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 21:15:06 by hexa              #+#    #+#             */
/*   Updated: 2020/09/28 16:03:41 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		sha3_update_prepare(t_sha3 *data, uint8_t *buf, size_t *len)
{
	unsigned int	old_tail;

	old_tail = ((8 - (*data).index_byte) & 7);
	if ((*len) < old_tail)
	{
		while ((*len)--)
			(*data).saved |= (uint64_t)(*(buf++)) <<
								(((*data).index_byte++) * 8);
		return ;
	}
	if (old_tail)
	{
		(*len) -= old_tail;
		while (old_tail--)
			(*data).saved |= (uint64_t)(*(buf++)) <<
								(((*data).index_byte++) * 8);
		(*data).s[(*data).index_word] ^= (*data).saved;
		(*data).index_byte = 0;
		(*data).saved = 0;
		if (++(*data).index_word == (25 - (*data).capa_word))
		{
			sha3_keccak((*data).s);
			(*data).index_word = 0;
		}
	}
}

static void		sha3_update_calc(t_sha3 *data, uint8_t *buf)
{
	uint64_t	t;

	t = (uint64_t)(buf[0]) |
		((uint64_t)(buf[1]) << 8 * 1) |
		((uint64_t)(buf[2]) << 8 * 2) |
		((uint64_t)(buf[3]) << 8 * 3) |
		((uint64_t)(buf[4]) << 8 * 4) |
		((uint64_t)(buf[5]) << 8 * 5) |
		((uint64_t)(buf[6]) << 8 * 6) |
		((uint64_t)(buf[7]) << 8 * 7);
	(*data).s[(*data).index_word] ^= t;
	if (++(*data).index_word == (25 - (*data).capa_word))
	{
		sha3_keccak((*data).s);
		(*data).index_word = 0;
	}
}

static void		sha3_update(t_sha3 *data, uint8_t *buf, size_t len)
{
	size_t			words;
	unsigned int	tail;
	size_t			i;

	sha3_update_prepare(data, buf, &len);
	words = len / sizeof(uint64_t);
	tail = len - words * sizeof(uint64_t);
	i = 0;
	while (i < words)
	{
		sha3_update_calc(data, buf);
		i++;
		buf += sizeof(uint64_t);
	}
	while (tail--)
		(*data).saved |= (uint64_t)(*(buf++)) << (((*data).index_byte++) * 8);
}

static void		sha3_final(t_sha3 *data)
{
	uint64_t		t;
	unsigned int	t1;
	unsigned int	t2;
	unsigned int	i;

	t = (uint64_t)(((uint64_t)(0x02 | (1 << 2))) << (((*data).index_byte) * 8));
	(*data).s[(*data).index_word] ^= (*data).saved ^ t;
	(*data).s[25 - (*data).capa_word - 1] ^= 0x8000000000000000;
	sha3_keccak((*data).s);
	i = 0;
	while (i < 25)
	{
		t1 = (uint32_t)(*data).s[i];
		t2 = (uint32_t)(((*data).s[i] >> 16) >> 16);
		(*data).sb[i * 8 + 0] = (uint8_t)(t1);
		(*data).sb[i * 8 + 1] = (uint8_t)(t1 >> 8);
		(*data).sb[i * 8 + 2] = (uint8_t)(t1 >> 16);
		(*data).sb[i * 8 + 3] = (uint8_t)(t1 >> 24);
		(*data).sb[i * 8 + 4] = (uint8_t)(t2);
		(*data).sb[i * 8 + 5] = (uint8_t)(t2 >> 8);
		(*data).sb[i * 8 + 6] = (uint8_t)(t2 >> 16);
		(*data).sb[i * 8 + 7] = (uint8_t)(t2 >> 24);
		i++;
	}
}

char			ft_sha3(int fd, t_digest *digest, size_t len)
{
	t_sha3		data;
	size_t		i;

	ft_bzero((&data), sizeof(data));
	data.capa_word = 2 * len / (8 * sizeof(uint64_t));
	data.hash.fd = fd;
	i = 0;
	while ((data.hash.len = read(data.hash.fd, data.buf, 1024)) > 0)
	{
		sha3_update((&data), data.buf, data.hash.len);
		i++;
	}
	sha3_final((&data));
	if (i == 1)
	{
		(*digest).text = ft_strdup((char*)data.buf);
		(*digest).len = data.hash.len;
	}
	len /= 4;
	if (!((*digest).ptr = ft_memalloc(len)))
		return (0);
	data.hash.i = 0;
	ft_memcpy((*digest).ptr, data.s, len);
	(*digest).size = len;
	return (1);
}
