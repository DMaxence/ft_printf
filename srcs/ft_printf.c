/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:00:59 by maduhoux          #+#    #+#             */
/*   Updated: 2018/04/06 16:17:06 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_printf_if(const char **format, t_flags *lst, int len, va_list args)
{
	int		(*tab[256])(t_flags *lst, va_list arg);

	ft_printf_tab(tab);
	*format += 1;
	*lst = ft_printf_lst_filler();
	*lst = ft_printf_flags_parser(format, lst);
	if (ft_printf_check_end(*(*format + 1)))
	{
		len += tab[(int)*(*format + 1)](lst, args);
		*format += 1;
	}
	else
		len += ft_printf_nothing(lst);
	return (len);
}

int		ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;
	t_flags lst;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			len = ft_printf_if(&format, &lst, len, args);
		}
		else if (*format)
		{
			ft_putchar(*format);
			len++;
		}
		format++;
	}
	va_end(args);
	return (len);
}
