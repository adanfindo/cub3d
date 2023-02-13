/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strthreejoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 12:07:35 by afindo           #+#    #+#             */
/*   Updated: 2022/08/17 14:53:19 by afindo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strthreejoin(char const *s1, char const *s2, char const *s3)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	k;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	new = malloc(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1);
	if (new == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		new[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		new[i + j] = s2[j];
	k = -1;
	while (s3[++k] != '\0')
		new[i + j + k] = s3[k];
	new[i + j + k] = '\0';
	return (new);
}
