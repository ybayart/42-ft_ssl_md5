/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <hexanyn@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 07:40:13 by hexa              #+#    #+#             */
/*   Updated: 2020/09/14 07:50:56 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		main(int argc, char** argv)
{
	int		i;

	i = 0;
	while (++i < argc)
		ft_md5(argv[i], ft_strlen(argv[i]));
}
