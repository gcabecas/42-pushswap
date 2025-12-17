/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndi-tull <ndi-tull@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:43:47 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/16 13:42:57 by ndi-tull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_pushswap	ps;

	if (argc < 2)
		return (1);
	check_input(argc, argv);
	init_pushswap(&ps);
	init(&ps.stack_a, argc, argv);
	ps.stack_b.head = NULL;
	ps.stack_b.tail = NULL;
	ps.disorder = (int)(compute_disorder(&ps.stack_a) * 100);
	ps.bench_mode = 1;
	ft_printf("=== BEFORE SORTING ===");
	print_stacks(&ps);
	chunk_solver(&ps);
	ft_printf("=== AFTER SORTING ===");
	print_stacks(&ps);
	print_stats(&ps);
	return (0);
}
