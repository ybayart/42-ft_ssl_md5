/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:59:55 by hexa              #+#    #+#             */
/*   Updated: 2020/09/16 16:10:41 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_puttab(int fd, size_t size, ...)
{
	va_list		list;
	size_t		i;
	char		*arg;
	ssize_t		len;

	va_start(list, size);
	i = 0;
	len = 0;
	while (i < size)
	{
		arg = va_arg(list, char*);
		len += write(fd, arg, ft_strlen(arg));
		i++;
	}
	va_end(list);
	return (len);
}
