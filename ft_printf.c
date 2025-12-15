/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:34:54 by gcabecas          #+#    #+#             */
/*   Updated: 2025/12/15 11:55:37 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	ft_putstr(char *str)
{
	size_t	len;

	if (!str)
		return (write(1, "(null)", 6));
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static size_t	ft_putnbr_rec(long nb)
{
	char	c;
	size_t	len;

	if (nb >= 10)
		len = ft_putnbr_rec(nb / 10);
	else
		len = 0;
	c = (nb % 10) + '0';
	write(1, &c, 1);
	return (len + 1);
}

size_t	ft_putnbr(int n)
{
	long	nb;
	size_t	len;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		len++;
		nb = -nb;
	}
	return (len + ft_putnbr_rec(nb));
}

size_t	choose_print(const char *str, size_t i, va_list *ap)
{
	size_t	len;

	if (str[i + 1] == 's')
		len = ft_putstr(va_arg(*ap, char *));
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		len = ft_putnbr(va_arg(*ap, int));
	else
		len = 0;
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	i;
	size_t	len;

	if (!str)
		return (-1);
	va_start(ap, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += choose_print(str, i, &ap);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			len ++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}
