/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:18:14 by afindo          #+#    #+#             */
/*   Updated: 2022/06/01 09:47:44 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

// Returns a substring of string s, starting at index start with length len
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	if (start > ft_strlen(s))
	{
		s2 = ft_calloc(1, 1);
		if (s2 == NULL)
			return (NULL);
		return (s2);
	}
	if (ft_strlen(s + start) < len)
		s2 = ft_calloc(ft_strlen(s + start) + 1, 1);
	else
		s2 = ft_calloc(len + 1, 1);
	if (s2 == NULL)
		return (NULL);
	s += start;
	i = 0;
	while (s[i] && i < len)
	{
		s2[i] = s[i];
		i++;
	}
	return (s2);
}
