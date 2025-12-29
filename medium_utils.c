/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:28:43 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/29 15:29:17 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_min(t_stack *stack)
{
	t_stck	*tmp;
	int		min;

	tmp = stack->head;
	min = tmp->nbr;
	while (tmp)
	{
		if (tmp->nbr < min)
			min = tmp->nbr;
		tmp = tmp->nxt;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	t_stck	*tmp;
	int		max;

	tmp = stack->head;
	max = tmp->nbr;
	while (tmp)
	{
		if (tmp->nbr > max)
			max = tmp->nbr;
		tmp = tmp->nxt;
	}
	return (max);
}
