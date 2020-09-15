/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <hexanyn@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 07:33:00 by hexa              #+#    #+#             */
/*   Updated: 2020/09/15 11:16:59 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

unsigned char	*ft_md5(char *str, size_t len);
void			ft_md5_fct_0(t_md5 *data);
void			ft_md5_fct_1(t_md5 *data);
void			ft_md5_fct_2(t_md5 *data);
void			ft_md5_fct_3(t_md5 *data);

unsigned char	*ft_sha256(char *str, size_t len);

char			padding_simple(t_hash *data, size_t size, void *(*fct)(void *,
														const void *, size_t));
void			prepare_hash(char *str, size_t len, t_hash *hash);

uint32_t		ft_left_rotate(uint32_t x, uint32_t n);
uint32_t		to_uint32(void *str);

#endif
