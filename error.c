/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:30:00 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/16 20:15:11 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	error_exit_free(t_pushswap *ps)
{
	if (ps)
	{
		if (ps->stack_a.head)
			free_stack(&ps->stack_a);
		if (ps->stack_b.head)
			free_stack(&ps->stack_b);
	}
	write(2, "Error\n", 6);
	exit(1);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicate(t_stack *stack, int nbr)
{
	t_stck	*tmp;

	tmp = stack->head;
	while (tmp)
	{
		if (tmp->nbr == nbr)
			return (1);
		tmp = tmp->nxt;
	}
	return (0);
}

void	check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			error_exit();
		i++;
	}
}
