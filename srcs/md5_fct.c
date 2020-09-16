/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:10:31 by hexa              #+#    #+#             */
/*   Updated: 2020/09/16 17:14:18 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_md5_fct_0(t_md5 *data)
{
	(*data).f = ((*data).m[1] & (*data).m[2]) |
		((~(*data).m[1]) & (*data).m[3]);
	(*data).g = (*data).hash.i;
}

void	ft_md5_fct_1(t_md5 *data)
{
	(*data).f = ((*data).m[3] & (*data).m[1]) |
		((~(*data).m[3]) & (*data).m[2]);
	(*data).g = (5 * (*data).hash.i + 1) % 16;
}

void	ft_md5_fct_2(t_md5 *data)
{
	(*data).f = (*data).m[1] ^ (*data).m[2] ^ (*data).m[3];
	(*data).g = (3 * (*data).hash.i + 5) % 16;
}

void	ft_md5_fct_3(t_md5 *data)
{
	(*data).f = (*data).m[2] ^ ((*data).m[1] | (~(*data).m[3]));
	(*data).g = (7 * (*data).hash.i) % 16;
}
