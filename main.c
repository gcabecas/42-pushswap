/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:43:47 by gcabecas          #+#    #+#             */
/*   Updated: 2026/01/05 12:05:14 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	adaptive_solver(t_pushswap *ps)
{
	if (ps->disorder < 0.2)
		simple_solver(ps);
	else if (ps->disorder < 0.5)
		medium_solver(ps);
	else
		complex_solver(ps);
}

static void	execute_solver(t_pushswap *ps)
{
	if (ps->strategy == 0)
		simple_solver(ps);
	else if (ps->strategy == 1)
		medium_solver(ps);
	else if (ps->strategy == 2)
		complex_solver(ps);
	else
		adaptive_solver(ps);
}

static void	display_result(t_pushswap *ps)
{
	if (ps->bench_mode)
		print_stats(ps);
}

static void	init_stacks(t_pushswap *ps, int argc, char **argv)
{
	check_input(argc, argv);
	init(&ps->stack_a, argc, argv);
	ps->stack_b.head = NULL;
	ps->stack_b.tail = NULL;
	ps->disorder = compute_disorder(&ps->stack_a);
}

int	main(int argc, char **argv)
{
	t_pushswap	ps;
	char		**new_argv;

	if (argc < 2)
		return (0);
	init_pushswap(&ps);
	parse_flags(&ps, &argc, argv);
	if (argc < 2)
		error_exit();
	new_argv = new_args(&argc, argv);
	init_stacks(&ps, argc, new_argv);
	free_expanded_args(new_argv, argc);
	execute_solver(&ps);
	display_result(&ps);
	free_stack(&ps.stack_a);
	free_stack(&ps.stack_b);
	return (0);
}
