/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:36:49 by afindo          #+#    #+#             */
/*   Updated: 2022/05/06 10:54:05 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstring(char *s)
{
	int		ans;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ans = 0;
	while (*s)
	{
		write(1, s, 1);
		ans++;
		s++;
	}
	return (ans);
}
