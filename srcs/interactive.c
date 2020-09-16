/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:31:29 by hexa              #+#    #+#             */
/*   Updated: 2020/09/16 14:20:18 by hexa             ###   ########.fr       */
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
	char	**args;

	line = NULL;
	while (42)
	{
		print_prompt(exec);
		if ((get_next_line(0, &line)) <= 0)
		{
			free(line);
			return (EXIT_FAILURE);
		}
		if ((args = ft_split(line, ' ')) == NULL)
		{
			free(line);
			return (EXIT_FAILURE);
		}
		parse_line(args, 0);
		free(line);
		ft_free_tab((void**)args);
	}
	return (EXIT_SUCCESS);
}
