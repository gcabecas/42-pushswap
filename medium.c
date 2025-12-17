/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndi-tull <ndi-tull@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:15:34 by ndi-tull          #+#    #+#             */
/*   Updated: 2025/12/16 14:20:43 by ndi-tull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <math.h>

// Compte le nombre d’éléments dans une stack.
// Utilisé pour :
// déterminer la taille des chunks
// choisir le sens des rotations

static int	stack_size(t_stack *stack)
{
	t_stck	*tmp;
	int		size;

	tmp = stack->head;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->nxt;
	}
	return (size);
}

// Retourne la plus petite valeur présente dans la stack.
// Sert à définir le début de l’intervalle global.

static int	find_min(t_stack *stack)
{
	t_stck	*tmp;
	int		min;

	tmp = stack->head;
	min = tmp->nbr;
	while (tmp)
	{
		if (tmp->nbr < min)
			min = tmp->nbr;
		tmp = tmp->nxt;
	}
	return (min);
}

// Retourne la plus grande valeur présente dans la stack.
// Sert à définir la fin de l’intervalle global.

static int	find_max(t_stack *stack)
{
	t_stck	*tmp;
	int		max;

	tmp = stack->head;
	max = tmp->nbr;
	while (tmp)
	{
		if (tmp->nbr > max)
			max = tmp->nbr;
		tmp = tmp->nxt;
	}
	return (max);
}

// Vérifie si un nombre appartient à un chunk donné.

static int	in_range(int nbr, int min, int max)
{
	return (nbr >= min && nbr <= max);
}

// Parcourt la stack A et pousse dans B tous les éléments
// dont la valeur est comprise dans [min ; max].
// Si le top de A appartient au chunk -> pb
// Sinon -> ra pour aller chercher un autre élément

static void	push_chunk(t_pushswap *ps, int min, int max)
{
	int	size;
	int	i;

	size = stack_size(&ps->stack_a);
	i = 0;
	while (i < size)
	{
		if (in_range(ps->stack_a.head->nbr, min, max))
			pb(ps);
		else
			ra(ps);
		i++;
	}
}

// Retourne la position (index) du plus grand élément
// présent dans la stack B.
// Utilisé pour déterminer s’il vaut mieux faire rb ou rrb.

static int	find_max_pos(t_stack *stack)
{
	t_stck	*tmp;
	int		max;
	int		pos;
	int		max_pos;

	tmp = stack->head;
	max = tmp->nbr;
	pos = 0;
	max_pos = 0;
	while (tmp)
	{
		if (tmp->nbr > max)
		{
			max = tmp->nbr;
			max_pos = pos;
		}
		tmp = tmp->nxt;
		pos++;
	}
	return (max_pos);
}

// Remonte le plus grand élément de la stack B vers le haut,
// en utilisant la rotation la moins coûteuse, puis le pousse
// dans la stack A.

static void	push_back_max(t_pushswap *ps)
{
	int	pos;
	int	size;

	size = stack_size(&ps->stack_b);
	pos = find_max_pos(&ps->stack_b);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(ps);
	}
	else
	{
		while (pos++ < size)
			rrb(ps);
	}
	pa(ps);
}

// Algorithme de tri par chunks (complexité O(n√n)).
// Étapes :
// 1) Calculer min, max et la taille des chunks
// 2) Pousser les éléments de A vers B par plages de valeurs
// 3) Remonter B vers A en récupérant toujours le maximum

void	chunk_solver(t_pushswap *ps)
{
	int	min;
	int	max;
	int	chunk_size;
	int	cur_min;
	int	cur_max;
	int	n;

	n = stack_size(&ps->stack_a);
	if (n <= 5)
		return (simple_solver(ps));
	min = find_min(&ps->stack_a);
	max = find_max(&ps->stack_a);
	chunk_size = (max - min) / sqrt(n) + 1;
	cur_min = min;
	cur_max = min + chunk_size;
	while (ps->stack_a.head)
	{
		push_chunk(ps, cur_min, cur_max);
		cur_min = cur_max + 1;
		cur_max += chunk_size;
	}
	while (ps->stack_b.head)
		push_back_max(ps);
}
