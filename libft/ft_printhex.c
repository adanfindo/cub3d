/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:09:35 by afindo          #+#    #+#             */
/*   Updated: 2022/05/07 17:49:47 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printhex(unsigned long l, int uppercase)
{
	int		ans;
	char	c;
	char	*hex_l;
	char	*hex_u;

	ans = 0;
	hex_l = "0123456789abcdef";
	hex_u = "0123456789ABCDEF";
	if (l > 15)
	{
		ans += ft_printhex(l / 16, uppercase);
	}
	if (uppercase)
		c = hex_u[l % 16];
	else
		c = hex_l[l % 16];
	write(1, &c, 1);
	return (ans + 1);
}

int	ft_printptr(void *ptr)
{
	if (!ptr)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	return (2 + ft_printhex((unsigned long) ptr, 0));
}

int	ft_print_x_u(unsigned int i)
{
	return (ft_printhex(i, 1));
}

int	ft_print_x_l(unsigned int i)
{
	return (ft_printhex(i, 0));
}
