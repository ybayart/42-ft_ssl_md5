/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:24:47 by hexa              #+#    #+#             */
/*   Updated: 2020/09/15 19:26:38 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	print_digest(t_digest digest)
{
	size_t			i;
	unsigned char	n;

	i = 0;
	while (i < (digest.size / 2))
	{
		n = digest.ptr[i];
		if (n < 16)
			write(1, "0", 1);
		ft_putnbr_base(n, "0123456789abcdef");
		i++;
	}
}
