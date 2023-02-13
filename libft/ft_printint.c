/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:00:33 by afindo          #+#    #+#             */
/*   Updated: 2022/05/09 16:54:23 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putposnbr(int i)
{
	int		ans;
	char	c;

	ans = 0;
	if (i > 9)
	{
		ans += ft_putposnbr(i / 10);
	}
	c = i % 10 + 48;
	write(1, &c, 1);
	return (ans + 1);
}

int	ft_printint(int i)
{
	int		ans;

	if (i == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	ans = 0;
	if (i < 0)
	{
		ans++;
		write(1, "-", 1);
		i *= -1;
	}
	return (ans + ft_putposnbr(i));
}
