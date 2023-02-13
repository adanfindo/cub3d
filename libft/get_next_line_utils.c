/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:27:16 by afindo          #+#    #+#             */
/*   Updated: 2022/08/16 14:05:43 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_linelen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	if (start > ft_strlen(s))
	{
		s2 = malloc(1);
		*s2 = '\0';
		return (s2);
	}
	if (ft_strlen(s + start) < len)
		s2 = malloc(ft_strlen(s + start) + 1);
	else
		s2 = malloc(len + 1);
	if (s2 == NULL)
		return (NULL);
	s += start;
	i = 0;
	while (s[i] && i < len)
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
