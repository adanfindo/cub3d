/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:51:21 by afindo          #+#    #+#             */
/*   Updated: 2022/06/01 09:47:55 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Gets the "length" of an int in digits
static int	ft_int_len(int i)
{
	int	j;

	j = 1;
	if (i < 0)
		i *= -1;
	while (i > 9)
	{
		i /= 10;
		j++;
	}
	return (j);
}

// Writes a positive number into a string
static char	*ft_putnbr_itoa(char *s, int n, int len)
{
	while (n > 9)
	{
		s[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	s[len - 1] = n + '0';
	return (s);
}

// Converts an int into a string
char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_int_len(n);
	if (n < 0)
	{
		if (n == -2147483648)
		{
			str = ft_calloc(12, 1);
			ft_strlcpy(str, "-2147483648", 12);
			return (str);
		}
		str = ft_calloc(len + 2, 1);
		if (str == NULL)
			return (NULL);
		*str = '-';
		str++;
		return (ft_putnbr_itoa(str, n * (-1), len) - 1);
	}
	str = ft_calloc(len + 1, 1);
	if (str == NULL)
		return (NULL);
	return (ft_putnbr_itoa(str, n, len));
}
