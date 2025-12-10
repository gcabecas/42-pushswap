/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:50:25 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/10 12:11:28 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	verif(t_stack *stack_a, t_stack *stack_b)
{
	t_stck	*tmp;

	tmp = stack_a->head;
	if (stack_b->head != NULL)
		return (1);
	if (tmp == NULL)
		return (1);
	while (tmp->nxt)
	{
		if (tmp->nbr < tmp->nxt->nbr)
			tmp = tmp->nxt;
		else
			return (1);
	}
	return (0);
}

void	simple_solver(t_stack *stack_a, t_stack *stack_b)
{
	int	sorted;

	sorted = 1;
	while (sorted)
	{
		if (stack_a->head == NULL)
		{
			while (stack_b->head != NULL)
				pa(stack_a, stack_b);
			if (verif(stack_a, stack_b) == 0)
				sorted = 0;
		}
		else if (stack_a->head->nxt
			&& stack_a->head->nbr > stack_a->head->nxt->nbr)
			sa(stack_a);
		else if (stack_a->head->nxt
			&& stack_a->head->nbr < stack_a->head->nxt->nbr)
			pb(stack_a, stack_b);
		else if (!stack_a->head->nxt)
			pb(stack_a, stack_b);
	}
}
