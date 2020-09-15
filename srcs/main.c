/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <hexanyn@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 07:40:13 by hexa              #+#    #+#             */
/*   Updated: 2020/09/15 12:28:06 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		main(int argc, char **argv)
{
	int				i;
	int				j;
	unsigned char	*digest;

	i = 0;
	while (++i < argc)
	{
		if ((digest = ft_sha256(argv[i], ft_strlen(argv[i]))) != NULL)
		{
			j = 0;
			while (j < 32)
				printf("%02x", (unsigned char)digest[j++]);
			printf("\n");
			free(digest);
		}
		i++;
	}
}
