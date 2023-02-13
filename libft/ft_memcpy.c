/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:58:55 by afindo          #+#    #+#             */
/*   Updated: 2022/05/11 10:23:12 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// Copies n spaces of memory from src to dst. Don't overlap!
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*start;

	start = dst;
	while (n--)
		*start++ = *((unsigned char *)src++);
	return (dst);
}
