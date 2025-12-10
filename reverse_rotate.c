/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:00:15 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/10 15:32:49 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <unistd.h>

static void	reverse_rotate(t_stack *stack)
{
	t_stck	*last;

	if (!stack || !stack->tail || !stack->tail->prv)
		return ;
	last = stack->tail;
	stack->tail = last->prv;
	stack->tail->nxt = NULL;
	last->prv = NULL;
	last->nxt = stack->head;
	stack->head->prv = last;
	stack->head = last;
}

void	rra(t_pushswap *ps)
{
	reverse_rotate(&ps->stack_a);
	ps->stats.rra_count++;
	ps->stats.total_ops++;
	if (!ps->bench_mode)
		printf("rra\n");
}

void	rrb(t_pushswap *ps)
{
	reverse_rotate(&ps->stack_b);
	ps->stats.rrb_count++;
	ps->stats.total_ops++;
	if (!ps->bench_mode)
		printf("rrb\n");
}

void	rrr(t_pushswap *ps)
{
	reverse_rotate(&ps->stack_a);
	reverse_rotate(&ps->stack_b);
	ps->stats.rrr_count++;
	ps->stats.total_ops++;
	if (!ps->bench_mode)
		printf("rrr\n");
}
