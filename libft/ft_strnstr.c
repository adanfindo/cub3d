/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:59:08 by afindo          #+#    #+#             */
/*   Updated: 2022/04/29 19:37:46 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

// Searches for the first occurence of needle in haystack and returns the 
// address of needle. NULL if not found
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_n;
	size_t	i;

	len_n = ft_strlen(needle);
	if (len_n == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		if (len_n + i <= len && ft_strncmp(&haystack[i], needle, len_n) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
