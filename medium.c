/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:15:34 by ndi-tull          #+#    #+#             */
/*   Updated: 2026/01/05 12:03:33 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	push_chunk(t_pushswap *ps, int min, int max)
{
	int	size;
	int	i;

	size = stack_size(&ps->stack_a);
	i = 0;
	while (i < size)
	{
		if (ps->stack_a.head->nbr >= min && ps->stack_a.head->nbr <= max)
		{
			pb(ps);
			if (ps->stack_b.head->nbr < min + (max - min) / 2)
				rb(ps);
		}
		else
			ra(ps);
		i++;
	}
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

static void	process_chunks(t_pushswap *ps, int min, int max, int size)
{
	int	chunk_size;
	int	cur_min;
	int	cur_max;

	chunk_size = (max - min) / ft_sqrt(size) + 1;
	cur_min = min;
	cur_max = min + chunk_size;
	while (ps->stack_a.head)
	{
		push_chunk(ps, cur_min, cur_max);
		cur_min = cur_max + 1;
		cur_max += chunk_size;
	}
}

void	medium_solver(t_pushswap *ps)
{
	int	size;

	size = stack_size(&ps->stack_a);
	process_chunks(ps, find_min(&ps->stack_a), find_max(&ps->stack_a), size);
	while (ps->stack_b.head)
		push_back_max(ps);
}
