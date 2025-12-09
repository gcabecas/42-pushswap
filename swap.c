/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:05:40 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/09 15:13:58 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <unistd.h>

static void	swap(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->head || !stack->head->nxt)
		return ;
	tmp = stack->head->nbr;
	stack->head->nbr = stack->head->nxt->nbr;
	stack->head->nxt->nbr = tmp;
}

void	sa(t_stack *stack_a)
{
	swap(stack_a);
	printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
	printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	printf("ss\n");
}
