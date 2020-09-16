/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:50:44 by hexa              #+#    #+#             */
/*   Updated: 2020/09/16 17:57:08 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	parse_std(t_parsing *parsing)
{
	t_digest	digest;

	init_digest(&digest);
	(*parsing).std = 0;
	digest.std = 1;
	calc_digest((*parsing), &(digest), 0);
}

char	parse_file(char *arg, t_parsing *parsing)
{
	int			fd;
	t_digest	digest;

	init_digest(&digest);
	if ((*parsing).std == 1 && isatty(STDIN_FILENO) == 0)
		parse_std(parsing);
	(*parsing).std = 0;
	if ((fd = open(arg, O_RDWR, 0600)) == -1)
	{
		error_errno(arg);
		return (1);
	}
	digest.file = arg;
	calc_digest((*parsing), &(digest), fd);
	close(fd);
	return (0);
}

void	parse_string(char **args, size_t *i, t_parsing *parsing)
{
	int			fd[2];
	t_digest	digest;

	init_digest(&digest);
	if ((*parsing).std == 1 && isatty(STDIN_FILENO) == 0)
		parse_std(parsing);
	(*parsing).std = 0;
	if (args[(*i) + 1] == NULL)
		error_2((*parsing).algo, ": flag s missing argument");
	else if (++(*i) != 0)
	{
		if (pipe(fd) == -1)
			error_errno((*parsing).algo);
		else
		{
			write(fd[1], args[(*i)], ft_strlen(args[(*i)]));
			close(fd[1]);
			digest.string = 1;
			digest.file = args[(*i)];
			calc_digest((*parsing), &(digest), fd[0]);
			close(fd[0]);
		}
	}
}
