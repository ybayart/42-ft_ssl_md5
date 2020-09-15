/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_384.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <hexanyn@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 07:40:50 by hexa              #+#    #+#             */
/*   Updated: 2020/09/15 18:42:42 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
** g_k:
** WIKIPEDIA: first 64 bits of the fractional parts of the cube roots of the
**            first 80 primes 2..409
**
** (*data).h[x]:
** WIKIPEDIA: first 64 bits of the fractional parts of the square roots of the
**            first 8 primes 2..19
**
** Those values is in constant to reduce exec time
*/

static uint64_t g_k[80] = {
	0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc, 0x3956c25bf348b538,
	0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118, 0xd807aa98a3030242, 0x12835b0145706fbe,
	0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2, 0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235,
	0xc19bf174cf692694, 0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
	0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5, 0x983e5152ee66dfab,
	0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4, 0xc6e00bf33da88fc2, 0xd5a79147930aa725,
	0x06ca6351e003826f, 0x142929670a0e6e70, 0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed,
	0x53380d139d95b3df, 0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b,
	0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30, 0xd192e819d6ef5218,
	0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8, 0x19a4c116b8d2d0c8, 0x1e376c085141ab53,
	0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373,
	0x682e6ff3d6b2b8a3, 0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
	0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b, 0xca273eceea26619c,
	0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178, 0x06f067aa72176fba, 0x0a637dc5a2c898a6,
	0x113f9804bef90dae, 0x1b710b35131c471b, 0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc,
	0x431d67c49c100d4c, 0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817
};

static void		prepare(char *str, size_t len, t_sha512 *data)
{
	prepare_hash(str, len, &((*data).hash));
	(*data).h[0] = 0xcbbb9d5dc1059ed8;
	(*data).h[1] = 0x629a292a367cd507;
	(*data).h[2] = 0x9159015a3070dd17;
	(*data).h[3] = 0x152fecd8f70e5939;
	(*data).h[4] = 0x67332667ffc00b31;
	(*data).h[5] = 0x8eb44a8768581511;
	(*data).h[6] = 0xdb0c2e0d64f98fa7;
	(*data).h[7] = 0x47b5481dbefa4fa4;
}

/*
** s[0]: S0
** s[1]: S1
** s[2]: ch
** s[3]: temp1
** s[4]: maj
** s[5]: temp2
*/

static void		work_calc_move(uint64_t (*m)[8], uint64_t s[6])
{
	(*m)[7] = (*m)[6];
	(*m)[6] = (*m)[5];
	(*m)[5] = (*m)[4];
	(*m)[4] = (*m)[3] + s[3];
	(*m)[3] = (*m)[2];
	(*m)[2] = (*m)[1];
	(*m)[1] = (*m)[0];
	(*m)[0] = s[3] + s[5];
}

static void		work_calc(t_sha512 *data)
{
	uint64_t	s[6];

	(*data).i = 0;
	while ((*data).i < 80)
	{
		s[0] = (ft_right_rotate_64((*data).m[0], 28))
			^ (ft_right_rotate_64((*data).m[0], 34))
			^ (ft_right_rotate_64((*data).m[0], 39));
		s[1] = (ft_right_rotate_64((*data).m[4], 14))
			^ (ft_right_rotate_64((*data).m[4], 18))
			^ (ft_right_rotate_64((*data).m[4], 41));
		s[2] = ((*data).m[4] & (*data).m[5])
			^ ((~(*data).m[4] & (*data).m[6]));
		s[3] = (*data).m[7] + s[1] + s[2] + g_k[(*data).i] +
											(*data).w[(*data).i];
		s[4] = ((*data).m[0] & (*data).m[1])
			^ ((*data).m[0] & (*data).m[2])
			^ ((*data).m[1] & (*data).m[2]);
		s[5] = s[0] + s[4];
		work_calc_move(&((*data).m), s);
		(*data).i++;
	}
}

static void		work(t_sha512 *data)
{
	size_t	i;
	int		j;

	i = 0;
	while (i < (*data).hash.blocks)
	{
		j = -1;
		while (++j < 16)
			ft_memrcpy((*data).w + j, (*data).hash.dst + (i * 128) + (j * 8), 8);
		j--;
		while (++j < 80)
			(*data).w[j] = sha512_makeword((*data).w, j);
		j = -1;
		while (++j < 8)
			(*data).m[j] = (*data).h[j];
		work_calc(data);
		j = -1;
		while (++j < 8)
			(*data).h[j] += (*data).m[j];
		i++;
	}
}

char			ft_sha512_384(char *str, size_t len, t_digest *digest)
{
	t_sha512		data;

	prepare(str, len, &data);
	if (padding_simple(&(data.hash), (1024 / 8), ft_memrcpy) == 0)
		return (0);
	work(&data);
	if (!((*digest).ptr = ft_memalloc(96)))
	{
		free(data.hash.dst);
		return (0);
	}
	data.i = 0;
	while (data.i < 6)
	{
		ft_memrcpy((*digest).ptr + (data.i * 8), &(data.h[data.i]), 8);
		data.i++;
	}
	(*digest).size = 96;
	free(data.hash.dst);
	return (1);
}
