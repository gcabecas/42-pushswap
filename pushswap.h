/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:47:43 by gcabecas          #+#    #+#             */
/*   Updated: 2026/01/03 15:02:43 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_stck
{
	int				nbr;
	int				index;
	struct s_stck	*nxt;
	struct s_stck	*prv;
}	t_stck;

typedef struct s_stack
{
	t_stck	*head;
	t_stck	*tail;
}	t_stack;

typedef struct s_stat
{
	int	total_ops;
	int	sa_count;
	int	sb_count;
	int	ss_count;
	int	pa_count;
	int	pb_count;
	int	ra_count;
	int	rb_count;
	int	rr_count;
	int	rra_count;
	int	rrb_count;
	int	rrr_count;
}	t_stat;

typedef struct s_pushswap
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_stat	stats;
	float	disorder;
	int		bench_mode;
	int		strategy;
}	t_pushswap;

void	init_pushswap(t_pushswap *ps);
void	init(t_stack *stack, int argc, char **argv);
t_stck	*stacknew(int nbr);
void	stackadd_back(t_stck **stck, t_stck *new);
size_t	stack_size(t_stack *s);
void	free_stack(t_stack *stack);
int		ft_atoi(char *str);
void	error_exit(void);
void	error_exit_free(t_pushswap *ps);
int		is_valid_number(char *str);
int		has_duplicate(t_stack *stack, int nbr);
void	check_input(int argc, char **argv);
void	parse_flags(t_pushswap *ps, int *argc, char **argv);
void	sa(t_pushswap *ps);
void	sb(t_pushswap *ps);
void	ss(t_pushswap *ps);
void	pa(t_pushswap *ps);
void	pb(t_pushswap *ps);
void	ra(t_pushswap *ps);
void	rb(t_pushswap *ps);
void	rr(t_pushswap *ps);
void	rra(t_pushswap *ps);
void	rrb(t_pushswap *ps);
void	rrr(t_pushswap *ps);
float	compute_disorder(t_stack *stack);
void	simple_solver(t_pushswap *ps);
void	complex_solver(t_pushswap *ps);
int		verif(t_stack *stack_a, t_stack *stack_b);
int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
void	print_stats(t_pushswap *ps);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
void	print_operation_counts(t_pushswap *ps);
int		assign_index(t_pushswap *ps);
void	medium_solver(t_pushswap *ps);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		find_max_pos(t_stack *stack);
int		ft_sqrt(int n);
char	**new_args(int *argc, char **argv);
void	free_expanded_args(char **args, int count);
int		is_space(char c);
int		count_words(char *str);
char	*extract_word(char *str, int *index);
char	**ft_split(char *str);
int		contains_space(char *str);
void	sort_low(t_pushswap *ps);

#endif