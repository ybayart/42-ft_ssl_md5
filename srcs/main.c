/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <hexanyn@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 07:40:13 by hexa              #+#    #+#             */
/*   Updated: 2020/09/14 17:49:15 by hexa             ###   ########.fr       */
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
		j = 0;
		digest = ft_md5(argv[i], ft_strlen(argv[i]));
		while (j < 16)
			printf("%02x", (unsigned char)digest[j++]);
		printf("\n");
		free(digest);
		i++;
	}
}
