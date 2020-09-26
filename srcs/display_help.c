/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:52:28 by hexa              #+#    #+#             */
/*   Updated: 2020/09/26 02:17:47 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	display_help_digest(void)
{
	ft_puttab(1, 9,
		"Message Digest commands\n",
		" md5\n",
		" sha1\n",
		" sha224		sha256\n",
		" sha384		sha512\n",
		" sha512-224	sha512-256\n",
		" sha3-256	sha3-384	sha3-512\n",
		" whirlpool\n",
		"\n");
}

static void	display_help_usage(void)
{
	ft_puttab(1, 5,
		"Common options\n",
		" -p	echo STDIN to STDOUT and append the checksum to STDOUT\n",
		" -q	quiet mode\n",
		" -r	reverse the format of the output\n",
		" -s	print the sum of the given string\n");
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
