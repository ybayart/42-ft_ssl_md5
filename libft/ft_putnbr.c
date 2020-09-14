/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:01:14 by racohen           #+#    #+#             */
/*   Updated: 2020/09/14 08:04:00 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	t;

	t = n;
	if (t < 0)
	{
		t *= -1;
		ft_putchar('-');
	}
	if (t > 9)
	{
		ft_putnbr((t / 10));
		ft_putchar((t % 10 + '0'));
	}
	else
		ft_putchar((t + '0'));
}

void	ft_putnbr_sizet(size_t n)
{
	long long	t;

	t = n;
	if (t < 0)
	{
		t *= -1;
		ft_putchar('-');
	}
	if (t > 9)
	{
		ft_putnbr((t / 10));
		ft_putchar((t % 10 + '0'));
	}
	else
		ft_putchar((t + '0'));
}
