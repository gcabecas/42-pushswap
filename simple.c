/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:50:25 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/10 12:36:29 by gcabecas         ###   ########lyon.fr   */
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

void	simple_solver(t_stack *stack_a, t_stack *stack_b) //trop d'op
{
	int	sorted;
	int	op;

	sorted = 1;
	op = 0;
	while (sorted)
	{
		if (stack_a->head == NULL)
		{
			while (stack_b->head != NULL)
				pa(stack_a, stack_b);
			if (verif(stack_a, stack_b) == 0)
				sorted = 0;
		}
		else if (stack_a->head->nxt
			&& stack_a->head->nbr > stack_a->head->nxt->nbr)
			sa(stack_a);
		else if (stack_a->head->nxt
			&& stack_a->head->nbr < stack_a->head->nxt->nbr)
			pb(stack_a, stack_b);
		else if (!stack_a->head->nxt)
			pb(stack_a, stack_b);
		op++;
	}
	printf("op = %i\n", op);
}

//./a.out 100 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
