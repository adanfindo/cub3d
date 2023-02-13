/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:58:49 by afindo          #+#    #+#             */
/*   Updated: 2022/04/29 19:39:11 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

// Trims a string s1 from the front and from the back, taking away all 
// occurences of chars containes in set
char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*s2;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= 0 && ft_strchr(set, s1[end]))
		end--;
	if (end < start)
	{
		s2 = ft_calloc(1, 1);
		if (s2 == NULL)
			return (NULL);
		return (s2);
	}
	s2 = ft_calloc(end - start + 2, 1);
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, &s1[start], end - start + 2);
	return (s2);
}
