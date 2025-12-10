/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:47:43 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/10 11:36:17 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>		//remplacer par ft_printf

typedef struct s_stck
{
	int				nbr;
	struct s_stck	*nxt;
	struct s_stck	*prv;
}	t_stck;

typedef struct s_stack
{
	t_stck	*head;
	t_stck	*tail;
	int		method;
	int		bench;
}	t_stack;

void	init(t_stack *stack, int argc, char **argv);
t_stck	*stacknew(int nbr);
void	stackadd_back(t_stck **stck, t_stck *new);
int		ft_atoi(char *str);
void	error_exit(void);
int		is_valid_number(char *str);
int		has_duplicate(t_stack *stack, int nbr);
void	check_input(int argc, char **argv);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
float	compute_disorder(t_stack *stack);
void	simple_solver(t_stack *stack_a, t_stack *stack_b);

#endif