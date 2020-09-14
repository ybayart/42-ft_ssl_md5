/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 09:37:43 by hexa              #+#    #+#             */
/*   Updated: 2020/09/14 10:09:42 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_get_hex(unsigned long long nb, int prev)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb < 16 && prev == 1)
		write(1, "0", 1);
	if (nb >= 16)
	{
		ft_get_hex(nb / 16, 0);
		ft_get_hex(nb % 16, 0);
	}
	else
	{
		write(1, (base + nb), 1);
	}
}

static void	ft_print_addr(unsigned long long addr)
{
	unsigned long long	tmp;
	int					i;

	tmp = addr;
	i = 1;
	while (i++ < 15)
	{
		if (tmp < 16)
			write(1, "0", 1);
		tmp /= 16;
	}
	ft_get_hex(addr, 0);
}

static void	ft_print_data(unsigned char *c, int size)
{
	int				i;
	unsigned char	i1;

	i = -1;
	while (i++ < 4)
	{
		write(1, " ", 1);
		if (i < size)
		{
			i1 = (1 << (sizeof(c[i]) * 8 - 1));
			while (i1)
			{
				write(1, ((c[i] & i1) != 0 ? "1" : "0"), 1);
				i1 >>= 1;
			}
		}
		else if (i != 4)
			write(1, "        ", 8);
	}
	i = -1;
	while (i++ < size - 1)
	{
		write(1, ft_isprint(c[i]) ? (char*)(c + i) : ".", 1);
	}
}

void		*ft_print_binary(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*c;
	unsigned int	sendsize;

	i = 0;
	c = addr;
	while (i * 4 < size)
	{
		if (i < size / 4)
			sendsize = 4;
		else
			sendsize = size % 4;
		ft_print_addr((unsigned long long)c + (i * 4));
		write(1, ":", 1);
		ft_print_data(c + (i * 4), sendsize);
		write(1, "\n", 1);
		i++;
	}
	return (addr);
}
