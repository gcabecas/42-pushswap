/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:31:50 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/09 15:16:46 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	add_to_stack(t_stack *stack, t_stck *tmp, int first)
{
	if (first)
	{
		stack->head = tmp;
		stack->tail = tmp;
	}
	else
	{
		stack->tail->nxt = tmp;
		tmp->prv = stack->tail;
		stack->tail = tmp;
	}
}

void	init(t_stack *stack, int argc, char **argv)
{
	int		i;
	int		nbr;
	t_stck	*tmp;

	i = 1;
	stack->head = NULL;
	stack->tail = NULL;
	while (i < argc)
	{
		nbr = ft_atoi(argv[i]);
		if (stack->head && has_duplicate(stack, nbr))
			error_exit();
		tmp = stacknew(nbr);
		add_to_stack(stack, tmp, (i == 1));
		i++;
	}
}
