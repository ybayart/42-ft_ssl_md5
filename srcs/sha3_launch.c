/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha3_launch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 01:37:43 by hexa              #+#    #+#             */
/*   Updated: 2020/09/28 16:07:15 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char		ft_sha3_128(int fd, t_digest *digest)
{
	return (ft_sha3(fd, digest, 128));
}

char		ft_sha3_256(int fd, t_digest *digest)
{
	return (ft_sha3(fd, digest, 256));
}

char		ft_sha3_384(int fd, t_digest *digest)
{
	return (ft_sha3(fd, digest, 384));
}

char		ft_sha3_512(int fd, t_digest *digest)
{
	return (ft_sha3(fd, digest, 512));
}
