/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:02:07 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/10 15:32:49 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <unistd.h>

static void	push(t_stack *src, t_stack *dst)
{
	t_stck	*tmp;

	if (!src || !src->head)
		return ;
	tmp = src->head;
	src->head = src->head->nxt;
	if (src->head)
		src->head->prv = NULL;
	else
		src->tail = NULL;
	tmp->nxt = dst->head;
	tmp->prv = NULL;
	if (dst->head)
		dst->head->prv = tmp;
	else
		dst->tail = tmp;
	dst->head = tmp;
}

void	pa(t_pushswap *ps)
{
	push(&ps->stack_b, &ps->stack_a);
	ps->stats.pa_count++;
	ps->stats.total_ops++;
	if (!ps->bench_mode)
		printf("pa\n");
}

void	pb(t_pushswap *ps)
{
	push(&ps->stack_a, &ps->stack_b);
	ps->stats.pb_count++;
	ps->stats.total_ops++;
	if (!ps->bench_mode)
		printf("pb\n");
}
