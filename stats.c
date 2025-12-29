/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:45:11 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/29 16:27:25 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	get_strategy_info(t_pushswap *ps, char **name, char **cmplx)
{
	if (ps->strategy == 0)
	{
		*name = "Simple";
		*cmplx = "O(n^2)";
	}
	else if (ps->strategy == 1)
	{
		*name = "Medium";
		*cmplx = "O(n√n)";
	}
	else if (ps->strategy == 2)
	{
		*name = "Complex";
		*cmplx = "O(n log n)";
	}
	else
	{
		*name = "Adaptive";
		*cmplx = "Varies";
	}
}

static void	print_disorder(float disorder)
{
	int	decimal;
	int	int_part;

	ft_putstr_fd("[bench] Disorder: ", 2);
	int_part = (int)(disorder * 100);
	ft_putnbr_fd(int_part, 2);
	write(2, ".", 1);
	decimal = (int)((disorder * 10000) - int_part * 100);
	ft_putnbr_fd(decimal, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_strategy_info(char *name, char *cmplx)
{
	ft_putstr_fd("[bench] Strategy: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(cmplx, 2);
	ft_putstr_fd("\n", 2);
}

void	print_stats(t_pushswap *ps)
{
	char	*strategy_name;
	char	*complexity;

	get_strategy_info(ps, &strategy_name, &complexity);
	print_disorder(ps->disorder);
	print_strategy_info(strategy_name, complexity);
	ft_putstr_fd("[bench] Total operations: ", 2);
	ft_putnbr_fd(ps->stats.total_ops, 2);
	write(2, "\n", 1);
	print_operation_counts(ps);
}
