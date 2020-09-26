/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:35:58 by hexa              #+#    #+#             */
/*   Updated: 2020/09/26 02:07:06 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef struct		s_digest
{
	size_t			size;
	unsigned char	*ptr;
	char			std;
	char			string;
	char			*file;
	char			*text;
	ssize_t			len;
}					t_digest;

typedef struct		s_parsing
{
	size_t			j;
	int				ret;
	char			quiet;
	char			reverse;
	char			print;
	char			std;
	char			opts;
	char			(*fct)();
	char			*algo;
}					t_parsing;

typedef struct		s_hash
{
	size_t			i;
	int				fd;
	size_t			blocks;
	ssize_t			len;
}					t_hash;

typedef struct		s_md5
{
	uint32_t		h[4];
	uint32_t		m[4];
	uint32_t		w[16];
	uint32_t		f;
	uint32_t		g;
	unsigned char	buf[64];
	t_hash			hash;
}					t_md5;

typedef struct		s_sha1
{
	uint32_t		h[5];
	uint32_t		m[5];
	uint32_t		w[80];
	uint32_t		f;
	uint32_t		k;
	unsigned char	buf[64];
	t_hash			hash;
}					t_sha1;

typedef struct		s_sha256
{
	uint32_t		h[8];
	uint32_t		m[8];
	uint32_t		w[64];
	unsigned char	buf[64];
	t_hash			hash;
}					t_sha256;

typedef struct		s_sha512
{
	uint64_t		h[8];
	uint64_t		m[8];
	uint64_t		w[80];
	unsigned char	buf[128];
	t_hash			hash;
}					t_sha512;

typedef struct		s_sha3
{
	uint64_t		saved;
	uint64_t		s[25];
	uint8_t			sb[200];
	unsigned		index_byte;
	unsigned		index_word;
	unsigned		capa_word;
	unsigned char	buf[1024];
	t_hash			hash;
}					t_sha3;

typedef struct		s_whirlpool
{
	uint64_t		h[8];
	uint64_t		w[8];
	uint64_t		k[8];
	unsigned char	buf[64];
	t_hash			hash;
}					t_whirlpool;

#endif
