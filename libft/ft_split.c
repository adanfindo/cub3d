/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:42:15 by afindo          #+#    #+#             */
/*   Updated: 2022/08/01 14:33:14 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

// Returns the number of substrings
static int	get_n_strings(char const *s, char c)
{
	int	n_strings;
	int	is_word;

	n_strings = 0;
	is_word = 0;
	while (*s)
	{
		if (*s != c && is_word == 0)
		{
			is_word = 1;
			n_strings++;
		}
		if (*s == c)
			is_word = 0;
		s++;
	}
	return (n_strings);
}

// Returns the length of string that is covered by separators
static int	ft_strlen_separator(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

// Splits a string according to separator c and returns an array of 
// substrings
char	**ft_split(char const *s, char c)
{
	int		n_strings;
	int		len_nxt;
	int		is_word;
	char	**arr_str;
	char	*str;

	n_strings = get_n_strings(s, c);
	arr_str = ft_calloc(n_strings + 1, sizeof(char *));
	is_word = 0;
	while (*s)
	{
		if (*s != c && is_word == 0)
		{
			is_word = 1;
			len_nxt = ft_strlen_separator(s, c);
			str = ft_calloc(len_nxt + 1, 1);
			ft_strlcpy(str, s, len_nxt + 1);
			*arr_str = str;
			arr_str++;
		}
		if (*s == c)
			is_word = 0;
		s++;
	}
	return (arr_str - n_strings);
}
