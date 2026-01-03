/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcabecas <gcabecas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:50:00 by gcabecas          #+#    #+#             */
/*   Updated: 2026/01/03 12:26:32 by gcabecas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

int	count_words(char *str)
{
	int	count;
	int	in_word;
	int	i;

	count = 0;
	in_word = 0;
	i = 0;
	while (str[i])
	{
		if (!is_space(str[i]) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_space(str[i]))
			in_word = 0;
		i++;
	}
	return (count);
}

char	*extract_word(char *str, int *index)
{
	int		start;
	int		len;
	char	*word;
	int		i;

	while (str[*index] && is_space(str[*index]))
		(*index)++;
	start = *index;
	len = 0;
	while (str[*index] && !is_space(str[*index]))
	{
		len++;
		(*index)++;
	}
	word = malloc(len + 1);
	if (!word)
		error_exit();
	i = 0;
	while (i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	int		word_count;
	char	**result;
	int		i;
	int		index;

	word_count = count_words(str);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		error_exit();
	i = 0;
	index = 0;
	while (i < word_count)
	{
		result[i] = extract_word(str, &index);
		i++;
	}
	result[word_count] = NULL;
	return (result);
}

int	contains_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_space(str[i]))
			return (1);
		i++;
	}
	return (0);
}
