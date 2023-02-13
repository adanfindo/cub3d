/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_e.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:27:14 by afindo            #+#    #+#             */
/*   Updated: 2022/11/28 09:27:14 by afindo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include "libft.h"

// Detects whitespace
static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || \
		c == '\r')
		return (1);
	return (0);
}

static int	char_to_i(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 10);
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	return (-1);
}

// Converts a string to int
int	ft_atoi_base_e(const char *str, int base, int *err)
{
	int	sign;
	int	num;
	int	i;

	sign = 1;
	num = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (base == 16 && ft_strncmp(str, "0x", 2) == 0)
		i += 2;
	if (str[i] == '-' || str[i] == '+')
		sign = 1 - 2 * (str[i++] == '-');
	while (char_to_i(str[i]) >= 0 && char_to_i(str[i]) <= base)
	{
		if (num > INT_MAX / base \
			|| (num == INT_MAX / base && str[i] - '0' > 7))
		{
			*err = 1;
			return (0);
		}
		num = base * num + (char_to_i(str[i++]));
	}
	return (num * sign);
}
