/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:12:53 by hexa              #+#    #+#             */
/*   Updated: 2020/09/15 20:23:50 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char		parse_line(char **args, size_t i)
{
	t_digest	digest;

	while (args[i] != NULL)
	{
		if (ft_sha512(args[i], ft_strlen(args[i]), &digest) != 0)
		{
			print_digest(digest);
			write(1, "\n", 1);
			free(digest.ptr);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
