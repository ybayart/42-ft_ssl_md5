/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <hexanyn@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 07:40:50 by hexa              #+#    #+#             */
/*   Updated: 2020/09/14 08:14:15 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char*	ft_md5(char* str, size_t len)
{
	size_t	it;
	char*	chain;

	it = len + 1;
	it = (((it % 512 > 448 ? it + 512 : it) / 512) + 1 ) * 512;
	if ((chain = malloc(it)) == NULL)
		return (NULL);
	return (str);
}
