/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:15:34 by ndi-tull          #+#    #+#             */
/*   Updated: 2025/12/29 15:32:10 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_sqrt(int n)
{
	int	x;
	int	prev;

	if (n <= 0)
		return (0);
	if (n == 1)
		return (1);
	x = n / 2;
	prev = 0;
	while (x != prev)
	{
		prev = x;
		x = (x + n / x) / 2;
	}
	return (x);
}

static void	push_chunk(t_pushswap *ps, int min, int max)
{
	int	size;
	int	i;

	size = stack_size(&ps->stack_a);
	i = 0;
	while (i < size)
	{
		if (ps->stack_a.head->nbr >= min && ps->stack_a.head->nbr <= max)
			pb(ps);
		else
			ra(ps);
		i++;
	}
}

static int	find_max_pos(t_stack *stack)
{
	t_stck	*tmp;
	int		max;
	int		pos;
	int		max_pos;

	tmp = stack->head;
	max = tmp->nbr;
	pos = 0;
	max_pos = 0;
	while (tmp)
	{
		if (tmp->nbr > max)
		{
			max = tmp->nbr;
			max_pos = pos;
		}
		tmp = tmp->nxt;
		pos++;
	}
	return (max_pos);
}

static void	push_back_max(t_pushswap *ps)
{
	int	pos;
	int	size;

	size = stack_size(&ps->stack_b);
	pos = find_max_pos(&ps->stack_b);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(ps);
	}
	else
	{
		while (pos++ < size)
			rrb(ps);
	}
	pa(ps);
}

void	medium_solver(t_pushswap *ps)
{
	int	min;
	int	max;
	int	chunk_size;
	int	cur_min;
	int	cur_max;

	if (stack_size(&ps->stack_a) <= 5)
		return (simple_solver(ps));
	min = find_min(&ps->stack_a);
	max = find_max(&ps->stack_a);
	chunk_size = (max - min) / ft_sqrt(stack_size(&ps->stack_a)) + 1;
	cur_min = min;
	cur_max = min + chunk_size;
	while (ps->stack_a.head)
	{
		push_chunk(ps, cur_min, cur_max);
		cur_min = cur_max + 1;
		cur_max += chunk_size;
	}
	while (ps->stack_b.head)
		push_back_max(ps);
}
