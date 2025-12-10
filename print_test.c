/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:30:00 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/10 15:38:36 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_stacks(t_pushswap *ps)
{
	t_stck	*tmp;

	printf("\nStack A: ");
	tmp = ps->stack_a.head;
	while (tmp)
	{
		printf("%d ", tmp->nbr);
		tmp = tmp->nxt;
	}
	printf("\nStack B: ");
	tmp = ps->stack_b.head;
	while (tmp)
	{
		printf("%d ", tmp->nbr);
		tmp = tmp->nxt;
	}
	printf("\n\n");
}

void	print_stats(t_pushswap *ps)
{
	printf("\n=== STATISTICS ===\n");
	printf("Total operations: %d\n", ps->stats.total_ops);
	printf("Disorder: %d%%\n", ps->disorder);
	printf("\nOperation counts:\n");
	printf("sa: %d\n", ps->stats.sa_count);
	printf("sb: %d\n", ps->stats.sb_count);
	printf("ss: %d\n", ps->stats.ss_count);
	printf("pa: %d\n", ps->stats.pa_count);
	printf("pb: %d\n", ps->stats.pb_count);
	printf("ra: %d\n", ps->stats.ra_count);
	printf("rb: %d\n", ps->stats.rb_count);
	printf("rr: %d\n", ps->stats.rr_count);
	printf("rra: %d\n", ps->stats.rra_count);
	printf("rrb: %d\n", ps->stats.rrb_count);
	printf("rrr: %d\n", ps->stats.rrr_count);
	printf("==================\n\n");
}
