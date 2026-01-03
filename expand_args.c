/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:50:00 by gcabecas          #+#    #+#             */
/*   Updated: 2026/01/03 12:28:30 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	count_new_args(int argc, char **argv)
{
	int	new_count;
	int	i;

	new_count = 0;
	i = 0;
	while (i < argc)
	{
		if (contains_space(argv[i]))
			new_count += count_words(argv[i]);
		else
			new_count++;
		i++;
	}
	return (new_count);
}

static void	copy_string(char *dst, char *src)
{
	int	j;

	j = 0;
	while (src[j])
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
}

static int	expand_with_space(char **new_argv, char *arg, int k)
{
	char	**split;
	int		j;

	split = ft_split(arg);
	j = 0;
	while (split[j])
	{
		new_argv[k] = split[j];
		k++;
		j++;
	}
	free(split);
	return (k);
}

static int	expand_without_space(char **new_argv, char *arg, int k)
{
	new_argv[k] = malloc(ft_strlen(arg) + 1);
	if (!new_argv[k])
		error_exit();
	copy_string(new_argv[k], arg);
	return (++k);
}

char	**expand_args(int *argc, char **argv)
{
	char	**new_argv;
	int		new_count;
	int		i;
	int		k;

	new_count = count_new_args(*argc, argv);
	new_argv = malloc(sizeof(char *) * (new_count + 1));
	if (!new_argv)
		error_exit();
	i = 0;
	k = 0;
	while (i < *argc)
	{
		if (contains_space(argv[i]))
			k = expand_with_space(new_argv, argv[i], k);
		else
			k = expand_without_space(new_argv, argv[i], k);
		i++;
	}
	new_argv[k] = NULL;
	*argc = new_count;
	return (new_argv);
}
