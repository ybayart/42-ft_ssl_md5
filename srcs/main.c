/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <hexanyn@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 07:40:13 by hexa              #+#    #+#             */
/*   Updated: 2020/09/15 18:43:11 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		main(int argc, char **argv)
{
	int				i;
	size_t			j;
	t_digest		digest;

	i = 0;
	while (++i < argc)
	{
		if (ft_sha512_384(argv[i], ft_strlen(argv[i]), &digest) != 0)
		{
			j = 0;
			while (j < (digest.size / 2))
				printf("%02x", (unsigned char)digest.ptr[j++]);
			printf("\n");
			free(digest.ptr);
		}
		i++;
	}
}
