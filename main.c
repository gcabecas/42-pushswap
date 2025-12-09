/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:43:47 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/09 12:07:47 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stck	*stck_a;
	t_stck	*stck_b;

	if (argc < 2)
		return (1);
	stck_a = init(stck_a, argc, argv);
	stck_b = malloc(sizeof(t_stck));
	while (stck_a)
	{
		printf("%i\n", stck_a->nbr);
		stck_a = stck_a->nxt;
	}
	return (0);
}
