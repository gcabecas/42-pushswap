/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stck_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:58:23 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/16 19:59:52 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_stck	*stacklast(t_stck *stck)
{
	t_stck	*tmp;

	tmp = stck;
	if (!stck)
		return (NULL);
	while (tmp->nxt)
		tmp = tmp->nxt;
	return (tmp);
}

void	stackadd_back(t_stck **stck, t_stck *new)
{
	t_stck	*last;

	if (!stck || !new)
		return ;
	if (!*stck)
	{
		*stck = new;
	}
	else
	{
		last = stacklast(*stck);
		last->nxt = new;
	}
}

t_stck	*stacknew(int nbr)
{
	t_stck	*stck;

	stck = malloc(sizeof(t_stck));
	if (!stck)
		error_exit();
	stck->nbr = nbr;
	stck->index = -1;
	stck->nxt = NULL;
	stck->prv = NULL;
	return (stck);
}

size_t	stack_size(t_stack *s)
{
	size_t	n;
	t_stck	*tmp;

	n = 0;
	tmp = s->head;
	while (tmp)
	{
		n++;
		tmp = tmp->nxt;
	}
	return (n);
}

void	free_stack(t_stack *stack)
{
	t_stck	*tmp;
	t_stck	*next;

	if (!stack)
		return ;
	tmp = stack->head;
	while (tmp)
	{
		next = tmp->nxt;
		free(tmp);
		tmp = next;
	}
	stack->head = NULL;
	stack->tail = NULL;
}
