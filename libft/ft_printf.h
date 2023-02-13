/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:07:42 by afindo          #+#    #+#             */
/*   Updated: 2022/05/31 10:38:44 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include "ft_printf.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_printchar(va_list *list);
int	ft_printstring(char *s);
int	ft_printint(int i);
int	ft_printuint(unsigned int i);
int	ft_printptr(void *ptr);
int	ft_print_x_u(unsigned int i);
int	ft_print_x_l(unsigned int i);

#endif