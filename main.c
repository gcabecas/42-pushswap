/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:43:47 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/16 19:00:22 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	adaptive_solver(t_pushswap *ps)
{
	if (ps->disorder < 20)
		simple_solver(ps);
	else if (ps->disorder < 50)
		ft_printf("mid");
	else
		complex_solver(ps);
}

static void	execute_solver(t_pushswap *ps)
{
	if (ps->strategy == 0)
		simple_solver(ps);
	else if (ps->strategy == 1)
		ft_printf("mid");
	else if (ps->strategy == 2)
		complex_solver(ps);
	else
		adaptive_solver(ps);
}

static void	display_result(t_pushswap *ps)
{
	if (!ps->bench_mode)
	{
		ft_printf("=== AFTER SORTING ===\n");
		print_stacks(ps);
	}
	if (ps->bench_mode)
		print_stats(ps);
}

static void	init_stacks(t_pushswap *ps, int argc, char **argv)
{
	check_input(argc, argv);
	init(&ps->stack_a, argc, argv);
	ps->stack_b.head = NULL;
	ps->stack_b.tail = NULL;
	ps->disorder = (int)(compute_disorder(&ps->stack_a) * 100);
	if (!ps->bench_mode)
	{
		ft_printf("=== BEFORE SORTING ===\n");
		print_stacks(ps);
	}
}

int	main(int argc, char **argv)
{
	t_pushswap	ps;

	if (argc < 2)
		return (1);
	init_pushswap(&ps);
	parse_flags(&ps, &argc, argv);
	if (argc < 2)
		return (1);
	init_stacks(&ps, argc, argv);
	execute_solver(&ps);
	display_result(&ps);
	return (0);
}
