/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:43:47 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/09 23:29:28 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_stck	*tmp;

	if (argc < 2)
		return (1);
	check_input(argc, argv);
	init(&stack_a, argc, argv);
	stack_b.head = NULL;
	stack_b.tail = NULL;
	printf("%.2f\n", compute_disorder(&stack_a));
	tmp = stack_a.head;
	while (tmp)
	{
		printf("%i\n", tmp->nbr);
		tmp = tmp->nxt;
	}
	(void)stack_b;
	return (0);
}
