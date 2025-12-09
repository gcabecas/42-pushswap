/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:31:50 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/09 12:04:06 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stck	*init(t_stck *stck, int argc, char **argv)
{
	int	i;
	int	nbr;

	i = 1;
	while (i < argc)
	{
		nbr = atoi(argv[i]);
		if (i == 1)
			stck = stacknew(nbr);
		else
			stackadd_back(&stck, stacknew(nbr));
		i++;
	}
	return (stck);
}
