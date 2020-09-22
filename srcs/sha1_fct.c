/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:10:31 by hexa              #+#    #+#             */
/*   Updated: 2020/09/22 12:02:45 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_sha1_fct_0(t_sha1 *data)
{
	(*data).f = ((*data).m[1] & (*data).m[2]) |
				((~(*data).m[1]) & (*data).m[3]);
	(*data).k = 0x5a827999;
}

void	ft_sha1_fct_1(t_sha1 *data)
{
	(*data).f = (*data).m[1] ^ (*data).m[2] ^ (*data).m[3];
	(*data).k = 0x6ed9eba1;
}

void	ft_sha1_fct_2(t_sha1 *data)
{
	(*data).f = ((*data).m[1] & (*data).m[2]) |
				((*data).m[1] & (*data).m[3]) |
				((*data).m[2] & (*data).m[3]);
	(*data).k = 0x8f1bbcdc;
}

void	ft_sha1_fct_3(t_sha1 *data)
{
	(*data).f = (*data).m[1] ^ (*data).m[2] ^ (*data).m[3];
	(*data).k = 0xca62c1d6;
}
