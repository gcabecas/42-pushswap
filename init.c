/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:31:50 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/16 18:40:51 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_pushswap(t_pushswap *ps)
{
	ps->stack_a.head = NULL;
	ps->stack_a.tail = NULL;
	ps->stack_b.head = NULL;
	ps->stack_b.tail = NULL;
	ps->stats.total_ops = 0;
	ps->stats.sa_count = 0;
	ps->stats.sb_count = 0;
	ps->stats.ss_count = 0;
	ps->stats.pa_count = 0;
	ps->stats.pb_count = 0;
	ps->stats.ra_count = 0;
	ps->stats.rb_count = 0;
	ps->stats.rr_count = 0;
	ps->stats.rra_count = 0;
	ps->stats.rrb_count = 0;
	ps->stats.rrr_count = 0;
	ps->disorder = 0;
	ps->bench_mode = 0;
	ps->strategy = 3;
}

static void	add_to_stack(t_stack *stack, t_stck *tmp, int first)
{
	if (first)
	{
		stack->head = tmp;
		stack->tail = tmp;
	}
	else
	{
		stack->tail->nxt = tmp;
		tmp->prv = stack->tail;
		stack->tail = tmp;
	}
}

void	init(t_stack *stack, int argc, char **argv)
{
	int		i;
	int		nbr;
	t_stck	*tmp;

	i = 1;
	stack->head = NULL;
	stack->tail = NULL;
	while (i < argc)
	{
		nbr = ft_atoi(argv[i]);
		if (stack->head && has_duplicate(stack, nbr))
			error_exit();
		tmp = stacknew(nbr);
		add_to_stack(stack, tmp, (i == 1));
		i++;
	}
}
