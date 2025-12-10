/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:43:47 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/10 12:52:01 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (1);
	check_input(argc, argv);
	init(&stack_a, argc, argv);
	stack_b.head = NULL;
	stack_b.tail = NULL;
	printf("%.2f\n", compute_disorder(&stack_a));
	// while (tmp)
	// {
	// 	printf("%i\n", tmp->nbr);
	// 	tmp = tmp->nxt;
	// }
	printf("\n");
	simple_solver(&stack_a, &stack_b);
	printf("\n");
	// tmp = stack_a.head;
	// while (tmp)
	// {
	// 	printf("%i\n", tmp->nbr);
	// 	tmp = tmp->nxt;
	// }
	return (0);
}
