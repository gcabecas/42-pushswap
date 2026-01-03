/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 14:55:03 by gcabecas          #+#    #+#             */
/*   Updated: 2026/01/03 16:45:23 by gcabecas         ###   ########lyon.fr   */
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