/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:56:46 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/10 14:57:05 by gcabecas         ###   ########lyon.fr   */
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