/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:50:25 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/10 14:58:50 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	find_min_pos(t_stack *stack)
{
	t_stck	*tmp;
	int		min;
	int		pos;
	int		min_pos;

	tmp = stack->head;
	min = tmp->nbr;
	pos = 0;
	min_pos = 0;
	while (tmp)
	{
		if (tmp->nbr < min)
		{
			min = tmp->nbr;
			min_pos = pos;
		}
		tmp = tmp->nxt;
		pos++;
	}
	return (min_pos);
}

static int	count_and_rotate(t_stack *stack_a, int *op)
{
	t_stck	*tmp;
	int		size;
	int		min_pos;

	tmp = stack_a->head;
	size = 0;
	while (tmp && ++size)
		tmp = tmp->nxt;
	if (size <= 0)
		return (0);
	min_pos = find_min_pos(stack_a);
	if (min_pos <= size / 2)
		while (min_pos-- > 0 && ++(*op))
			ra(stack_a);
	else
		while (min_pos++ < size && ++(*op))
			rra(stack_a);
	return (1);
}

void	simple_solver(t_stack *stack_a, t_stack *stack_b)
{
	int	op;

	op = 0;
	while (verif(stack_a, stack_b))
	{
		if (!count_and_rotate(stack_a, &op))
			break ;
		pb(stack_a, stack_b);
		op++;
	}
	while (stack_b->head && ++op)
		pa(stack_a, stack_b);
	printf("op = %i\n", op);
}
