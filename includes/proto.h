/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <hexanyn@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 07:33:00 by hexa              #+#    #+#             */
/*   Updated: 2020/09/28 16:03:55 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

char			ft_md5(int fd, t_digest *digest);
void			ft_md5_fct_0(t_md5 *data);
void			ft_md5_fct_1(t_md5 *data);
void			ft_md5_fct_2(t_md5 *data);
void			ft_md5_fct_3(t_md5 *data);

char			ft_sha1(int fd, t_digest *digest);
uint32_t		sha1_makeword(uint32_t w[80], int j);
void			ft_sha1_fct_0(t_sha1 *data);
void			ft_sha1_fct_1(t_sha1 *data);
void			ft_sha1_fct_2(t_sha1 *data);
void			ft_sha1_fct_3(t_sha1 *data);

char			ft_sha256(int fd, t_digest *digest);
char			ft_sha256_224(int fd, t_digest *digest);
uint32_t		sha256_makeword(uint32_t w[64], int j);

char			ft_sha512(int fd, t_digest *digest);
char			ft_sha512_224(int fd, t_digest *digest);
char			ft_sha512_256(int fd, t_digest *digest);
char			ft_sha512_384(int fd, t_digest *digest);
uint64_t		sha512_makeword(uint64_t w[64], int j);

char			ft_sha3_128(int fd, t_digest *digest);
char			ft_sha3_256(int fd, t_digest *digest);
char			ft_sha3_384(int fd, t_digest *digest);
char			ft_sha3_512(int fd, t_digest *digest);
char			ft_sha3(int fd, t_digest *digest, size_t len);
void			sha3_keccak(uint64_t st[25]);

char			ft_whirlpool(int fd, t_digest *digest);
void			ft_whirlpool_sub_bytes(uint64_t *data);
void			ft_whirlpool_shift_cols(uint64_t *data);
void			ft_whirlpool_mix_rows(uint64_t *data);

void			padding(void *buf, size_t src, size_t size, void *(*fct)());
void			padding_whirlpool(void *buf, size_t src);
void			padding_size(void *buf, size_t src, size_t size,
																void *(*fct)());
void			padding_size_128(void *buf, __uint128_t src, size_t size,
																void *(*fct)());
void			padding_size_whirlpool(void *buf, size_t src);

uint32_t		ft_right_rotate(uint32_t x, uint32_t n);
uint32_t		ft_left_rotate(uint32_t x, uint32_t n);
uint64_t		ft_right_rotate_64(uint64_t x, uint64_t n);
uint64_t		ft_left_rotate_64(uint64_t x, uint64_t n);

uint32_t		ft_right_shift(uint32_t x, uint32_t n);
uint32_t		ft_left_shift(uint32_t x, uint32_t n);
uint64_t		ft_right_shift_64(uint64_t x, uint64_t n);
uint64_t		ft_left_shift_64(uint64_t x, uint64_t n);

char			run_interactive(char *exec);

void			display_help(void);
void			display_help_short(char *arg);

char			parse_line(char **args, size_t start);
void			parse_std(t_parsing *parsing);
char			parse_file(char *arg, t_parsing *parsing);
void			parse_string(char **args, size_t *i, t_parsing *parsing);

void			calc_digest(t_parsing parsing, t_digest *digest, int fd);

void			init_parsing(t_parsing *parsing);
void			init_digest(t_digest *digest);

void			error_errno(char *arg);
void			error_2(char *s1, char *s2);
void			error_4(char *s1, char *s2, char *s3, char *s4);

#endif
