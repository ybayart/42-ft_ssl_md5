/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:12:53 by hexa              #+#    #+#             */
/*   Updated: 2020/09/16 18:04:28 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static char	(*g_fct[5])() = {
	ft_md5, ft_sha256, ft_sha256_224, ft_sha512, ft_sha512_384
};

static char	*g_index[5] = {
	"md5", "sha256", "sha224", "sha512", "sha384"
};

static char	parse_opt(char **args, size_t *i, t_parsing *data)
{
	if (ft_strcmp(args[(*i)], "-s") == 0)
	{
		parse_string(args, i, data);
		return (0);
	}
	if (ft_strncmp(args[(*i)], "-", 1) != 0 || (*data).opts == 1)
	{
		(*data).opts = 1;
		return (1);
	}
	else if (ft_strcmp(args[(*i)], "-q") == 0)
		(*data).quiet = 1;
	else if (ft_strcmp(args[(*i)], "-r") == 0)
		(*data).reverse = 1;
	else if (ft_strcmp(args[(*i)], "-p") == 0)
		(*data).print = 1;
	else
	{
		error_4(g_index[(*data).j], ": ", "Unrecognized flag ", args[(*i)] + 1);
		return (-1);
	}
	return (0);
}

static char	parse_init(char **args, size_t i, t_parsing *parsing)
{
	if (args[i] == NULL)
		return (1);
	if (ft_strcmp(args[i], "help") == 0)
	{
		display_help();
		return (0);
	}
	init_parsing(parsing);
	while (g_index[(*parsing).j] != NULL && ft_strcmp(g_index[(*parsing).j],
																args[i]) != 0)
		(*parsing).j++;
	if ((*parsing).j == 5)
	{
		display_help_short(args[i]);
		return (1);
	}
	return (2);
}

char		parse_line(char **args, size_t i)
{
	t_parsing	data;
	int			ret;

	if ((ret = parse_init(args, i, &data)) != 2)
		return (ret);
	data.fct = g_fct[data.j];
	data.algo = g_index[data.j];
	while (args[++i] != NULL)
	{
		if ((data.ret = parse_opt(args, &i, &data)) == -1)
			return (EXIT_FAILURE);
		else if (data.ret == 2)
			continue ;
		else if (data.ret == 1)
			parse_file(args[i], &data);
	}
	if (data.std == 1)
		parse_std(&data);
	return (EXIT_SUCCESS);
}
