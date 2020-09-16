/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:43:55 by hexa              #+#    #+#             */
/*   Updated: 2020/09/16 17:02:38 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	init_parsing(t_parsing *parsing)
{
	(*parsing).j = 0;
	(*parsing).quiet = 0;
	(*parsing).reverse = 0;
	(*parsing).print = 0;
	(*parsing).std = 1;
	(*parsing).opts = 0;
}

void	init_digest(t_digest *digest)
{
	(*digest).size = 0;
	(*digest).ptr = NULL;
	(*digest).std = 0;
	(*digest).string = 0;
	(*digest).file = NULL;
	(*digest).text = NULL;
}
