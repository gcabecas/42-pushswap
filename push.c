/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:02:07 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/10 11:55:40 by gcabecas         ###   ########lyon.fr   */
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

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	printf("pb\n");
}
