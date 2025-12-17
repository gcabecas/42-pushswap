/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndi-tull <ndi-tull@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:47:43 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/16 13:52:04 by ndi-tull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <limits.h>
# include <math.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stck
{
	int				nbr;
	struct s_stck	*nxt;
	struct s_stck	*prv;
}					t_stck;

typedef struct s_stack
{
	t_stck			*head;
	t_stck			*tail;
}					t_stack;

typedef struct s_stat
{
	int				total_ops;
	int				sa_count;
	int				sb_count;
	int				ss_count;
	int				pa_count;
	int				pb_count;
	int				ra_count;
	int				rb_count;
	int				rr_count;
	int				rra_count;
	int				rrb_count;
	int				rrr_count;
}					t_stat;

typedef struct s_pushswap
{
	t_stack			stack_a;
	t_stack			stack_b;
	t_stat			stats;
	int				disorder;
	int				bench_mode;
	int				strategy;
}					t_pushswap;

void				init_pushswap(t_pushswap *ps);
void				init(t_stack *stack, int argc, char **argv);
t_stck				*stacknew(int nbr);
void				stackadd_back(t_stck **stck, t_stck *new);
int					ft_atoi(char *str);
void				error_exit(void);
int					is_valid_number(char *str);
int					has_duplicate(t_stack *stack, int nbr);
void				check_input(int argc, char **argv);
void				sa(t_pushswap *ps);
void				sb(t_pushswap *ps);
void				ss(t_pushswap *ps);
void				pa(t_pushswap *ps);
void				pb(t_pushswap *ps);
void				ra(t_pushswap *ps);
void				rb(t_pushswap *ps);
void				rr(t_pushswap *ps);
void				rra(t_pushswap *ps);
void				rrb(t_pushswap *ps);
void				rrr(t_pushswap *ps);
float				compute_disorder(t_stack *stack);
void				simple_solver(t_pushswap *ps);
int					verif(t_stack *stack_a, t_stack *stack_b);
int					ft_printf(const char *str, ...);
size_t				ft_strlen(const char *s);
// test
void				print_stacks(t_pushswap *ps);
void				print_stats(t_pushswap *ps);
void				chunk_solver(t_pushswap *ps);

#endif