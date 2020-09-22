/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:38:25 by racohen           #+#    #+#             */
/*   Updated: 2020/09/22 02:29:56 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst8;
	unsigned char	*src8;
	__uint128_t		*dst128;
	__uint128_t		*src128;
	size_t			i;

	if (src == NULL && dst == NULL)
		return (NULL);
	dst128 = (__uint128_t*)dst;
	src128 = (__uint128_t*)src;
	i = n / sizeof(__uint128_t);
	while (i--)
		*dst128++ = *src128++;
	dst8 = (unsigned char*)dst128;
	src8 = (unsigned char*)src128;
	i = n % sizeof(__uint128_t);
	while (i--)
		*dst8++ = *src8++;
	return (dst);
}
