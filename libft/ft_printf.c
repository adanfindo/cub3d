/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:55:06 by afindo          #+#    #+#             */
/*   Updated: 2022/05/07 17:50:39 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_arg(char c, va_list *lst_ptr);

int	ft_printf(const char *format, ...)
{
	va_list	list;
	va_list	*lst_ptr;
	int		count;

	va_start(list, format);
	lst_ptr = &list;
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_write_arg(*format, lst_ptr);
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(list);
	return (count);
}

static int	ft_write_arg(char c, va_list *lst_ptr)
{
	if (c == 'c')
		return (ft_printchar(lst_ptr));
	if (c == 's')
		return (ft_printstring(va_arg(*lst_ptr, char *)));
	if (c == 'i' || c == 'd')
		return (ft_printint(va_arg(*lst_ptr, int)));
	if (c == 'u')
		return (ft_printuint(va_arg(*lst_ptr, unsigned int)));
	if (c == '%')
	{
		write(1, "%%", 1);
		return (1);
	}
	if (c == 'p')
		return (ft_printptr(va_arg(*lst_ptr, void *)));
	if (c == 'x')
		return (ft_print_x_l(va_arg(*lst_ptr, unsigned int)));
	if (c == 'X')
		return (ft_print_x_u(va_arg(*lst_ptr, unsigned int)));
	return (0);
}
