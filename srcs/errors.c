/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 11:49:04 by hexa              #+#    #+#             */
/*   Updated: 2020/09/16 15:06:50 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		error_errno(char *arg)
{
	if (arg != NULL)
	{
		write(2, arg, ft_strlen(arg));
		write(2, ": ", 2);
	}
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
}

void		error_2(char *s1, char *s2)
{
	write(2, s1, ft_strlen(s1));
	write(2, s2, ft_strlen(s2));
	write(2, "\n", 1);
}

void		error_4(char *s1, char *s2, char *s3, char *s4)
{
	write(2, s1, ft_strlen(s1));
	write(2, s2, ft_strlen(s2));
	write(2, s3, ft_strlen(s3));
	write(2, s4, ft_strlen(s4));
	write(2, "\n", 1);
}
