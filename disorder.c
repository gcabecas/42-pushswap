/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:10:11 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/09 15:27:56 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	get_stack_size(t_stack *stack)
{
	int		size;
	t_stck	*tmp;

	size = 0;
	tmp = stack->head;
	while (tmp)
	{
		size++;
		tmp = tmp->nxt;
	}
	return (size);
}

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

double	compute_disorder(t_stack *stack)
{
	int		size;
	int		mistakes;
	int		total_pairs;

	size = get_stack_size(stack);
	if (size <= 1)
		return (0.0);
	mistakes = count_mistakes(stack, size);
	total_pairs = (size * (size - 1)) / 2;
	return ((double)mistakes / (double)total_pairs);
}
