/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:50:25 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/10 15:28:45 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	find_min_pos(t_stack *stack)
{
	t_stck	*tmp;
	int		min;
	int		pos;
	int		min_pos;

	tmp = stack->head;
	min = tmp->nbr;
	pos = 0;
	min_pos = 0;
	while (tmp)
	{
		if (tmp->nbr < min)
		{
			min = tmp->nbr;
			min_pos = pos;
		}
		tmp = tmp->nxt;
		pos++;
	}
	return (min_pos);
}

static int	count_and_rotate(t_pushswap *ps)
{
	t_stck	*tmp;
	int		size;
	int		min_pos;

	tmp = ps->stack_a.head;
	size = 0;
	while (tmp && ++size)
		tmp = tmp->nxt;
	if (size <= 0)
		return (0);
	min_pos = find_min_pos(&ps->stack_a);
	if (min_pos <= size / 2)
		while (min_pos-- > 0)
			ra(ps);
	else
		while (min_pos++ < size)
			rra(ps);
	return (1);
}

void	simple_solver(t_pushswap *ps)
{
	while (verif(&ps->stack_a, &ps->stack_b))
	{
		if (!count_and_rotate(ps))
			break ;
		pb(ps);
	}
	while (ps->stack_b.head)
		pa(ps);
}

//./a.out 100 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1