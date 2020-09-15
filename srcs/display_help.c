/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:52:28 by hexa              #+#    #+#             */
/*   Updated: 2020/09/15 20:08:49 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	display_help_digest(void)
{
	write(1, "Message Digest commands\n", 24);
	write(1, "md5		sha224		sha384\n", 20);
	write(1, "		sha256		sha512\n", 17);
	write(1, "\n", 1);
}

static void	display_help_usage(void)
{
	write(1, "Common options\n", 15);
	write(1, "-p	echo STDIN to STDOUT and append the checksum to STDOUT\n", 58);
	write(1, "-q	quit mode\n", 13);
	write(1, "-r	reverse the format of the output\n", 36);
	write(1, "-s	print the sum of the given string\n", 37);
}

void	display_help(void)
{
	display_help_digest();
	display_help_usage();
}
