/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_buf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 21:39:35 by ybayart           #+#    #+#             */
/*   Updated: 2020/09/28 20:25:45 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			get_next_buf(int fd, char *line, size_t len)
{
	char	*buf;
	int		ret;
	int		ret2;
	size_t	diff;

	if (read(fd, NULL, 0) < 0)
		return (-1);
	if ((buf = ft_memalloc(len)) == NULL)
		return (-1);
	ret2 = 0;
	while ((diff = len - ret2) != 0)
	{
		if ((ret = read(fd, buf + ret2, (diff < 64 ? diff : 64))) < 0)
		{
			free(buf);
			return (-1);
		}
		ret2 += ret;
		if (ret == 0)
			break ;
	}
	ft_memcpy(line, buf, ret2);
	free(buf);
	return (ret2);
}
