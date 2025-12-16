/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:31:16 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/16 20:15:47 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	rank_in_arr(int *arr, int n, int val)
{
	int	i;
	int	rank;

	i = 0;
	rank = 0;
	while (i < n)
	{
		if (arr[i] < val)
			rank++;
		i++;
	}
	return (rank);
}

int	assign_index(t_pushswap *ps)
{
	int		n;
	int		i;
	int		*arr;
	t_stck	*cur;

	n = stack_size(&ps->stack_a);
	arr = (int *)malloc(sizeof(int) * n);
	if (!arr)
		error_exit_free(ps);
	cur = ps->stack_a.head;
	i = 0;
	while (i < n)
	{
		arr[i] = cur->nbr;
		cur = cur->nxt;
		i++;
	}
	cur = ps->stack_a.head;
	while (cur)
	{
		cur->index = rank_in_arr(arr, n, cur->nbr);
		cur = cur->nxt;
	}
	free(arr);
	return (0);
}
