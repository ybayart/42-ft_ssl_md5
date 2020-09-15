/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <hexanyn@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 07:40:50 by hexa              #+#    #+#             */
/*   Updated: 2020/09/15 11:23:56 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		work(t_sha256 *data)
{
	size_t	i;

	i = 0;
	while (i < (*data).hash.blocks)
	{
		i++;
	}
}

unsigned char	*ft_sha256(char *str, size_t len)
{
	t_sha256		data;
	unsigned char	*digest;

	prepare_hash(str, len, &(data.hash));
	if (padding_simple(&(data.hash), (512 / 8), ft_memrcpy) == 0)
		return (NULL);
	return (0);
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
