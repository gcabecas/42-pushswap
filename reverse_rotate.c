/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:00:15 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/09 15:13:47 by gcabecas         ###   ########lyon.fr   */
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

void	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	printf("rra\n");
}

void	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	printf("rrr\n");
}
