/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stck_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:58:23 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/09 15:28:59 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stck	*stacklast(t_stck *stck)
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
	stck->nxt = NULL;
	stck->prv = NULL;
	return (stck);
}
