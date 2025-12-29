/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:05:40 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/29 16:00:26 by gcabecas         ###   ########lyon.fr   */
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
	tmp = stack->head->index;
	stack->head->index = stack->head->nxt->index;
	stack->head->nxt->index = tmp;
}

void	sa(t_pushswap *ps)
{
	swap(&ps->stack_a);
	ps->stats.sa_count++;
	ps->stats.total_ops++;
	ft_printf("sa\n");
}

void	sb(t_pushswap *ps)
{
	swap(&ps->stack_b);
	ps->stats.sb_count++;
	ps->stats.total_ops++;
	ft_printf("sb\n");
}

void	ss(t_pushswap *ps)
{
	swap(&ps->stack_a);
	swap(&ps->stack_b);
	ps->stats.ss_count++;
	ps->stats.total_ops++;
	ft_printf("ss\n");
}
