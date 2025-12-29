/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:45:54 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/29 16:08:48 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	c = (nb % 10) + '0';
	write(fd, &c, 1);
}

void	print_operation_counts(t_pushswap *ps)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(ps->stats.sa_count, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(ps->stats.sb_count, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(ps->stats.ss_count, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(ps->stats.pa_count, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(ps->stats.pb_count, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(ps->stats.ra_count, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(ps->stats.rb_count, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(ps->stats.rr_count, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(ps->stats.rra_count, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(ps->stats.rrb_count, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(ps->stats.rrr_count, 2);
	write(2, "\n", 1);
}
