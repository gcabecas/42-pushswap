/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndi-tull <ndi-tull@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:43:47 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/30 11:44:57 by ndi-tull         ###   ########.fr       */
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

	if (argc < 2)
		return (0);
	init_pushswap(&ps);
	parse_flags(&ps, &argc, argv);
	if (argc < 2)
		error_exit();
	init_stacks(&ps, argc, argv);
	execute_solver(&ps);
	display_result(&ps);
	free_stack(&ps.stack_a);
	free_stack(&ps.stack_b);
	return (0);
}
