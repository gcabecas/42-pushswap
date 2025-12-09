/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:47:43 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/09 11:58:32 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>

typedef struct s_stck
{
	int				nbr;
	struct s_stck	*nxt;
}	t_stck;

t_stck	*init(t_stck *stck, int argc, char **argv);
t_stck	*stacknew(int nbr);
void	stackadd_back(t_stck **stck, t_stck *new);
int		ft_atoi(char *str);

#endif