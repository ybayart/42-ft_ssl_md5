/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memxor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 19:17:04 by hexa              #+#    #+#             */
/*   Updated: 2020/09/21 19:22:47 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memxor(void *dst, void *src, size_t count)
{
	unsigned char	*dst8;
	unsigned char	*src8;
	__uint128_t		*dst128;
	__uint128_t		*src128;
	size_t			i;

	dst128 = (__uint128_t*)dst;
	src128 = (__uint128_t*)src;
	i = count / sizeof(__uint128_t);
	while (i--)
		*dst128++ ^= *src128++;
	dst8 = (unsigned char *)dst128;
	src8 = (unsigned char *)src128;
	i = count % sizeof(__uint128_t);
	while (i--)
		*dst8++ ^= *src8++;
	return (dst);
}
