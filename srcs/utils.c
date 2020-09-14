/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:07:32 by hexa              #+#    #+#             */
/*   Updated: 2020/09/14 17:28:15 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t	ft_left_rotate(uint32_t x, uint32_t n)
{
	return ((x << n) | (x >> (32 - n)));
}

uint32_t	to_uint32(void *str)
{
	uint32_t	dst;

	dst = 0;
	dst = (dst | ((char*)str)[3]) << 8;
	dst = (dst | ((char*)str)[2]) << 8;
	dst = (dst | ((char*)str)[1]) << 8;
	dst |= ((char*)str)[0];
	return (dst);
}
