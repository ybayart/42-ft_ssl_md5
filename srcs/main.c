/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <hexanyn@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 07:40:13 by hexa              #+#    #+#             */
/*   Updated: 2020/09/28 19:35:38 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		main(int argc, char **argv)
{
	char	ret;

	ret = EXIT_SUCCESS;
	if (argc == 1)
	{
		ret = run_interactive(argv[0]);
	}
	else
	{
		ret = parse_line(argv, 1);
	}
	return (ret);
}
