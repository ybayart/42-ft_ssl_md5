/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_224.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <hexanyn@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 07:40:50 by hexa              #+#    #+#             */
/*   Updated: 2020/09/16 17:29:37 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
** g_k:
** WIKIPEDIA: first 32 bits of the fractional parts of the cube roots of the
**            first 64 primes 2..311
**
** (*data).h[x]:
** WIKIPEDIA: first 32 bits of the fractional parts of the square roots of the
**            first 8 primes 2..19
**
** Those values is in constant to reduce exec time
*/

static uint32_t g_k[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
	0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe,
	0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa,
	0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
	0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb,
	0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624,
	0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
	0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb,
	0xbef9a3f7, 0xc67178f2
};

static void		prepare(int fd, t_sha256 *data)
{
	(*data).hash.fd = fd;
	(*data).h[0] = 0xc1059ed8;
	(*data).h[1] = 0x367cd507;
	(*data).h[2] = 0x3070dd17;
	(*data).h[3] = 0xf70e5939;
	(*data).h[4] = 0xffc00b31;
	(*data).h[5] = 0x68581511;
	(*data).h[6] = 0x64f98fa7;
	(*data).h[7] = 0xbefa4fa4;
	(*data).hash.i = 0;
	while ((*data).hash.i < 64)
		(*data).w[(*data).hash.i++] = (uint32_t)0;
	(*data).hash.i = 0;
}

/*
** s[0]: S0
** s[1]: S1
** s[2]: ch
** s[3]: temp1
** s[4]: maj
** s[5]: temp2
*/

static void		work_calc(t_sha256 *data)
{
	uint32_t	s[6];

	s[0] = (ft_right_rotate((*data).m[0], 2))
		^ (ft_right_rotate((*data).m[0], 13))
		^ (ft_right_rotate((*data).m[0], 22));
	s[1] = (ft_right_rotate((*data).m[4], 6))
		^ (ft_right_rotate((*data).m[4], 11))
		^ (ft_right_rotate((*data).m[4], 25));
	s[2] = ((*data).m[4] & (*data).m[5])
		^ ((~(*data).m[4] & (*data).m[6]));
	s[3] = (*data).m[7] + s[1] + s[2] + g_k[(*data).hash.i] +
										(*data).w[(*data).hash.i];
	s[4] = ((*data).m[0] & (*data).m[1])
		^ ((*data).m[0] & (*data).m[2])
		^ ((*data).m[1] & (*data).m[2]);
	s[5] = s[0] + s[4];
	(*data).m[7] = (*data).m[6];
	(*data).m[6] = (*data).m[5];
	(*data).m[5] = (*data).m[4];
	(*data).m[4] = (*data).m[3] + s[3];
	(*data).m[3] = (*data).m[2];
	(*data).m[2] = (*data).m[1];
	(*data).m[1] = (*data).m[0];
	(*data).m[0] = s[3] + s[5];
}

static void		work_one_block(t_sha256 *data)
{
	int		j;

	j = -1;
	while (++j < 16)
		ft_memrcpy((*data).w + j, (*data).buf + (j * 4), 4);
	j--;
	while (++j < 64)
		(*data).w[j] = sha256_makeword((*data).w, j);
	j = -1;
	while (++j < 8)
		(*data).m[j] = (*data).h[j];
	(*data).hash.i = 0;
	while ((*data).hash.i < 64)
	{
		work_calc(data);
		(*data).hash.i++;
	}
	j = -1;
	while (++j < 8)
		(*data).h[j] += (*data).m[j];
}

static void		work(t_sha256 *data)
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

char			ft_sha256_224(int fd, t_digest *digest)
{
	t_sha256		data;

	prepare(fd, &data);
	work(&data);
	if (data.hash.blocks == 0)
	{
		(*digest).text = ft_strdup((char*)data.buf);
		(*digest).len = data.hash.len;
	}
	if (!((*digest).ptr = ft_memalloc(56)))
		return (0);
	data.hash.i = 0;
	while (data.hash.i < 7)
	{
		ft_memrcpy((*digest).ptr + (data.hash.i * 4),
									&(data.h[data.hash.i]), 4);
		data.hash.i++;
	}
	(*digest).size = 56;
	return (1);
}
