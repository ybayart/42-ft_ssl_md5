/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:24:47 by hexa              #+#    #+#             */
/*   Updated: 2020/09/16 17:39:06 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	infos(t_digest digest, t_parsing parsing, char state)
{
	if (state == 0 && parsing.reverse == 0 && parsing.quiet == 0)
	{
		if (digest.std == 1)
			write(1, "|> ", 4);
		else if (digest.string == 1)
			ft_puttab(1, 4, parsing.algo, "[\"", digest.file, "\"]= ");
		else
			ft_puttab(1, 4, parsing.algo, "(", digest.file, ")= ");
	}
	else if (state == 1 && parsing.reverse == 1 && parsing.quiet == 0)
	{
		if (digest.std == 1)
			write(1, " *stdin", 7);
		else if (digest.string == 1)
			ft_puttab(1, 3, " \"", digest.file, "\"");
		else
			ft_puttab(1, 2, " ", digest.file);
	}
}

static void	print_digest(t_digest digest, t_parsing parsing)
{
	size_t			i;
	unsigned char	n;

	i = 0;
	if (parsing.print == 1 && digest.std == 1 && digest.text != NULL)
	{
		if (parsing.quiet == 0)
			write(1, digest.text, digest.len);
		write(1, "\n", 1);
		free(digest.text);
	}
	infos(digest, parsing, 0);
	while (i < (digest.size / 2))
	{
		n = digest.ptr[i];
		if (n < 16)
			write(1, "0", 1);
		ft_putnbr_base(n, "0123456789abcdef");
		i++;
	}
	infos(digest, parsing, 1);
	write(1, "\n", 1);
}

void		calc_digest(t_parsing parsing, t_digest *digest, int fd)
{
	if (parsing.fct(fd, digest) != 0)
		print_digest((*digest), parsing);
}
