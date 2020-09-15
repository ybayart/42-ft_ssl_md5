/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:35:58 by hexa              #+#    #+#             */
/*   Updated: 2020/09/15 18:38:08 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef struct		s_hash
{
	size_t			srclen;
	__uint128_t		dstlen;
	char			*src;
	unsigned char	*dst;
	size_t			blocks;
}					t_hash;

typedef struct		s_digest
{
	size_t			size;
	unsigned char	*ptr;
}					t_digest;

typedef struct		s_md5
{
	t_hash			hash;
	uint32_t		h[4];
	uint32_t		m[4];
	uint32_t		w[16];
	size_t			i;
	uint32_t		f;
	uint32_t		g;
}					t_md5;

typedef struct		s_sha256
{
	t_hash			hash;
	uint32_t		h[8];
	uint32_t		m[8];
	uint32_t		w[64];
	size_t			i;
}					t_sha256;

typedef struct		s_sha512
{
	t_hash			hash;
	uint64_t		h[8];
	uint64_t		m[8];
	uint64_t		w[80];
	size_t			i;
}					t_sha512;

#endif
