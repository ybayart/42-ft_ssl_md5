/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <hexanyn@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 07:33:00 by hexa              #+#    #+#             */
/*   Updated: 2020/09/15 20:14:46 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

char			ft_md5(char *str, size_t len, t_digest *digest);
void			ft_md5_fct_0(t_md5 *data);
void			ft_md5_fct_1(t_md5 *data);
void			ft_md5_fct_2(t_md5 *data);
void			ft_md5_fct_3(t_md5 *data);

char			ft_sha256(char *str, size_t len, t_digest *digest);
char			ft_sha256_224(char *str, size_t len, t_digest *digest);
uint32_t		sha256_makeword(uint32_t w[64], int j);

char			ft_sha512(char *str, size_t len, t_digest *digest);
char			ft_sha512_384(char *str, size_t len, t_digest *digest);
uint64_t		sha512_makeword(uint64_t w[64], int j);

char			padding_simple(t_hash *data, size_t size, void *(*fct)(void *,
														const void *, size_t));
void			prepare_hash(char *str, size_t len, t_hash *hash);

uint32_t		ft_left_rotate(uint32_t x, uint32_t n);
uint32_t		ft_right_rotate(uint32_t x, uint32_t n);
uint32_t		ft_right_shift(uint32_t x, uint32_t n);
uint64_t		ft_right_rotate_64(uint64_t x, uint64_t n);
uint64_t		ft_right_shift_64(uint64_t x, uint64_t n);

char			run_interactive(char *exec);
void			display_help(void);
char			parse_line(char **args, size_t start);
void			print_digest(t_digest digest);


#endif
