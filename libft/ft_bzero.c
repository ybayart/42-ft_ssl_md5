/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:36:08 by racohen           #+#    #+#             */
/*   Updated: 2020/09/22 01:36:14 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr8;
	__uint128_t		*ptr128;
	size_t			i;

	ptr128 = (__uint128_t*)s;
	i = n / 16;
	while (i--)
		*ptr128++ = (__uint128_t)0;
	ptr8 = (unsigned char*)ptr128;
	i = n % 16;
	while (i--)
		*ptr8++ = (__uint128_t)0;
}
