/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:31:29 by hexa              #+#    #+#             */
/*   Updated: 2020/09/15 19:49:26 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		print_prompt(char *exec)
{
	write(1, exec, ft_strlen(exec));
	write(1, "> ", 2);
}

char			run_interactive(char *exec)
{
	char	*line;

	line = NULL;
	while (42)
	{
		print_prompt(exec);
		if ((get_next_line(0, &line)) <= 0)
		{
			free(line);
			return(EXIT_FAILURE);
		}
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		free(line);
	}
	return (EXIT_SUCCESS);
}
