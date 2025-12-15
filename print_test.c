/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:30:00 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/15 11:28:22 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_stacks(t_pushswap *ps)
{
	t_stck	*tmp;

	ft_printf("\nStack A: ");
	tmp = ps->stack_a.head;
	while (tmp)
	{
		ft_printf("%d ", tmp->nbr);
		tmp = tmp->nxt;
	}
	ft_printf("\nStack B: ");
	tmp = ps->stack_b.head;
	while (tmp)
	{
		ft_printf("%d ", tmp->nbr);
		tmp = tmp->nxt;
	}
	ft_printf("\n\n");
}

void	print_stats(t_pushswap *ps)
{
	ft_printf("\n=== STATISTICS ===\n");
	ft_printf("Total operations: %d\n", ps->stats.total_ops);
	ft_printf("Disorder: %d%%\n", ps->disorder);
	ft_printf("\nOperation counts:\n");
	ft_printf("sa: %d\n", ps->stats.sa_count);
	ft_printf("sb: %d\n", ps->stats.sb_count);
	ft_printf("ss: %d\n", ps->stats.ss_count);
	ft_printf("pa: %d\n", ps->stats.pa_count);
	ft_printf("pb: %d\n", ps->stats.pb_count);
	ft_printf("ra: %d\n", ps->stats.ra_count);
	ft_printf("rb: %d\n", ps->stats.rb_count);
	ft_printf("rr: %d\n", ps->stats.rr_count);
	ft_printf("rra: %d\n", ps->stats.rra_count);
	ft_printf("rrb: %d\n", ps->stats.rrb_count);
	ft_printf("rrr: %d\n", ps->stats.rrr_count);
	ft_printf("==================\n\n");
}
