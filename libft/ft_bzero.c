/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:28:14 by afindo            #+#    #+#             */
/*   Updated: 2022/11/28 09:28:14 by afindo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// Nulls n bytes of memory beginning at s
void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*c;

	i = 0;
	while (i < n)
	{
		c = s + i;
		*c = '\0';
		i++;
	}
}
