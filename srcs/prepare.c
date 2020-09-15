/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:14:48 by hexa              #+#    #+#             */
/*   Updated: 2020/09/15 11:16:20 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		prepare_hash(char *str, size_t len, t_hash *hash)
{
	(*hash).src = str;
	(*hash).dst = NULL;
	(*hash).srclen = len;
	(*hash).dstlen = 0;
	(*hash).blocks = 0;
}
