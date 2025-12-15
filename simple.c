/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:50:25 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/15 11:59:12 by gcabecas         ###   ########lyon.fr   */
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

static int	count_and_rotate(t_pushswap *ps)
{
	t_stck	*tmp;
	int		size;
	int		min_pos;

	tmp = ps->stack_a.head;
	size = 0;
	while (tmp && ++size)
		tmp = tmp->nxt;
	if (size <= 0)
		return (0);
	min_pos = find_min_pos(&ps->stack_a);
	if (min_pos <= size / 2)
		while (min_pos-- > 0)
			ra(ps);
	else
		while (min_pos++ < size)
			rra(ps);
	return (1);
}

void	simple_solver(t_pushswap *ps)
{
	while (verif(&ps->stack_a, &ps->stack_b))
	{
		if (!count_and_rotate(ps))
			break ;
		pb(ps);
	}
	while (ps->stack_b.head)
		pa(ps);
}
