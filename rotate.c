/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:05:03 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/10 15:32:49 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <unistd.h>

static void	rotate(t_stack *stack)
{
	t_stck	*first;

	if (!stack || !stack->head || !stack->head->nxt)
		return ;
	first = stack->head;
	stack->head = first->nxt;
	stack->head->prv = NULL;
	first->nxt = NULL;
	first->prv = stack->tail;
	stack->tail->nxt = first;
	stack->tail = first;
}

void	ra(t_pushswap *ps)
{
	rotate(&ps->stack_a);
	ps->stats.ra_count++;
	ps->stats.total_ops++;
	if (!ps->bench_mode)
		printf("ra\n");
}

void	rb(t_pushswap *ps)
{
	rotate(&ps->stack_b);
	ps->stats.rb_count++;
	ps->stats.total_ops++;
	if (!ps->bench_mode)
		printf("rb\n");
}

void	rr(t_pushswap *ps)
{
	rotate(&ps->stack_a);
	rotate(&ps->stack_b);
	ps->stats.rr_count++;
	ps->stats.total_ops++;
	if (!ps->bench_mode)
		printf("rr\n");
}
