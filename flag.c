/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:54:49 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/16 14:05:42 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	is_flag(char *arg)
{
	if (!arg)
		return (0);
	if (ft_strcmp(arg, "--bench") == 0)
		return (1);
	if (ft_strcmp(arg, "--simple") == 0)
		return (1);
	if (ft_strcmp(arg, "--medium") == 0)
		return (1);
	if (ft_strcmp(arg, "--complex") == 0)
		return (1);
	if (ft_strcmp(arg, "--adaptive") == 0)
		return (1);
	return (0);
}

static void	handle_bench_flag(t_pushswap *ps, int *bench)
{
	if (*bench > 0)
		error_exit();
	ps->bench_mode = 1;
	(*bench)++;
}

static void	handle_strategy_flag(t_pushswap *ps, char *arg, int *strat)
{
	if (*strat > 0)
		error_exit();
	if (ft_strcmp(arg, "--simple") == 0)
		ps->strategy = 0;
	else if (ft_strcmp(arg, "--medium") == 0)
		ps->strategy = 1;
	else if (ft_strcmp(arg, "--complex") == 0)
		ps->strategy = 2;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		ps->strategy = 3;
	(*strat)++;
}

static void	parse_single_flag(t_pushswap *ps, char *arg, int *strat, int *b)
{
	if (ft_strcmp(arg, "--bench") == 0)
		handle_bench_flag(ps, b);
	else
		handle_strategy_flag(ps, arg, strat);
}

void	parse_flags(t_pushswap *ps, int *argc, char **argv)
{
	int	i;
	int	j;
	int	strategy_count;
	int	bench_count;

	i = 1;
	j = 1;
	strategy_count = 0;
	bench_count = 0;
	while (i < *argc)
	{
		if (is_flag(argv[i]))
			parse_single_flag(ps, argv[i], &strategy_count, &bench_count);
		else
		{
			argv[j] = argv[i];
			j++;
		}
		i++;
	}
	*argc = j;
}
