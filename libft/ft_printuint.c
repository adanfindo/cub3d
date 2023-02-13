/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:00:33 by afindo          #+#    #+#             */
/*   Updated: 2022/05/07 17:49:55 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printuint(unsigned int i)
{
	int		ans;
	char	c;

	ans = 0;
	if (i > 9)
	{
		ans += ft_printuint(i / 10);
	}
	c = i % 10 + 48;
	write(1, &c, 1);
	ans ++;
	return (ans);
}
