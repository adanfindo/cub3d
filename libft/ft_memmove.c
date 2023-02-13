/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:58:57 by afindo          #+#    #+#             */
/*   Updated: 2022/04/29 19:24:48 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// Copies n spaces of memory from src to dst. May overlap. Non destructive.
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*start;

	start = dst;
	if (src < dst && dst < src + len)
	{
		start += len - 1;
		src += len - 1;
		while (len--)
			*start-- = *((char *)src--);
		return (dst);
	}
	while (len--)
		*start++ = *((char *)src++);
	return (dst);
}
