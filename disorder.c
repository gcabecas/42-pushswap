/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndi-tull <ndi-tull@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:10:11 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/30 12:39:15 by ndi-tull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	get_element_at(t_stack *stack, int index)
{
	int		i;
	t_stck	*tmp;

	i = 0;
	tmp = stack->head;
	while (tmp && i < index)
	{
		tmp = tmp->nxt;
		i++;
	}
	if (tmp)
		return (tmp->nbr);
	return (0);
}

float	compute_disorder(t_stack *stack)
{
	float	mistakes;
	float	total_pairs;
	int		i;
	int		j;
	int		size;

	i = 0;
	mistakes = 0;
	total_pairs = 0;
	size = stack_size(stack);
	while (i <= size - 1)
	{
		j = i + 1;
		while (j <= size - 1)
		{
			if (get_element_at(stack, i) > get_element_at(stack, j))
				mistakes++;
			total_pairs++;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}
