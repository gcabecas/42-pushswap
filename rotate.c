/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:05:03 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/09 15:13:46 by gcabecas         ###   ########lyon.fr   */
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

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	printf("rr\n");
}
