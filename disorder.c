/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:10:11 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/17 13:10:51 by gcabecas         ###   ########lyon.fr   */
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

static int	count_mistakes(t_stack *stack, int size)
{
	int	mistakes;
	int	i;
	int	j;

	mistakes = 0;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (get_element_at(stack, i) > get_element_at(stack, j))
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes);
}

float	compute_disorder(t_stack *stack)
{
	int		size;
	int		mistakes;
	int		total_pairs;

	size = stack_size(stack);
	if (size <= 1)
		return (0.0);
	mistakes = count_mistakes(stack, size);
	total_pairs = (size * (size - 1)) / 2;
	return ((float)mistakes / (float)total_pairs);
}
