/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:50:21 by afindo          #+#    #+#             */
/*   Updated: 2022/04/29 19:27:37 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Writes a positive number to fs
static void	ft_putposnbr_fd(int n, int fd)
{
	char	c;

	if (n > 9)
	{
		ft_putposnbr_fd(n / 10, fd);
	}
	c = n % 10 + 48;
	write(fd, &c, 1);
}

// Writes a number to fd
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	ft_putposnbr_fd(n, fd);
}
