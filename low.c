/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 14:55:03 by gcabecas          #+#    #+#             */
/*   Updated: 2026/01/05 09:57:08 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_low(t_pushswap *ps)
{
	int	max_pos;

	max_pos = find_max_pos(&ps->stack_a);
	if (max_pos == 0)
		ra(ps);
	else if (max_pos == 1)
		rra(ps);
	if (ps->stack_a.head->nbr > ps->stack_a.head->nxt->nbr)
		sa(ps);
}

int	quick_sort(t_pushswap *ps)
{
	int	size;

	size = stack_size(&ps->stack_a);
	if (size == 2 && ps->stack_a.head->nbr > ps->stack_a.head->nxt->nbr)
	{
		sa(ps);
		return (1);
	}
	if (size == 3)
	{
		sort_low(ps);
		return (1);
	}
	return (0);
}
