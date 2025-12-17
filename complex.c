/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:54:42 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/16 20:15:48 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	bits_needed(int max)
{
	int	bits;

	bits = 0;
	while (max > 0)
	{
		max = max / 2;
		bits++;
	}
	return (bits);
}

static int	bit_value(int index, int bit)
{
	int	p;

	p = 1;
	while (bit > 0)
	{
		p = p * 2;
		bit--;
	}
	return ((index / p) % 2);
}

static void	radix_sort(t_pushswap *ps)
{
	int	n;
	int	bits;
	int	bit;
	int	i;

	n = stack_size(&ps->stack_a);
	if (n <= 1)
		return ;
	bits = bits_needed(n - 1);
	bit = 0;
	while (bit < bits)
	{
		i = 0;
		while (i < n)
		{
			if (bit_value(ps->stack_a.head->index, bit) == 0)
				pb(ps);
			else
				ra(ps);
			i++;
		}
		while (ps->stack_b.head)
			pa(ps);
		bit++;
	}
}

void	complex_solver(t_pushswap *ps)
{
	if (assign_index(ps) < 0)
		return ;
	radix_sort(ps);
}
