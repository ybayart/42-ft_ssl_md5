/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:52:28 by hexa              #+#    #+#             */
/*   Updated: 2020/09/16 17:23:17 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	display_help_digest(void)
{
	write(1, "Message Digest commands\n", 24);
	write(1, "md5		sha256		sha512\n", 20);
	write(1, "		sha224		sha384\n", 17);
	write(1, "\n", 1);
}

static void	display_help_usage(void)
{
	write(1, "Common options\n", 15);
	write(1, "-p	echo STDIN to STDOUT and append the checksum to STDOUT\n",
																		58);
	write(1, "-q	quiet mode\n", 14);
	write(1, "-r	reverse the format of the output\n", 36);
	write(1, "-s	print the sum of the given string\n", 37);
}

void		display_help(void)
{
	display_help_digest();
	display_help_usage();
}

void		display_help_short(char *arg)
{
	write(1, "Invalid command '", 17);
	write(1, arg, ft_strlen(arg));
	write(1, "'; type \"help\" for a list.\n", 27);
}
