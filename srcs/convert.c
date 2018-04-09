/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:11:46 by maduhoux          #+#    #+#             */
/*   Updated: 2018/01/23 17:11:33 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_printf_converter_signed(t_flags *lst, va_list arg)
{
	if (lst->hh)
		return ((char)va_arg(arg, int));
	else if (lst->h)
		return ((short int)va_arg(arg, int));
	else if (lst->ll)
		return (va_arg(arg, long long int));
	else if (lst->l)
		return (va_arg(arg, long int));
	else if (lst->j)
		return (va_arg(arg, intmax_t));
	else if (lst->z)
		return (va_arg(arg, ssize_t));
	return (va_arg(arg, int));
}

uintmax_t	ft_printf_converter_unsigned(t_flags *lst, va_list arg)
{
	if (lst->hh)
		return ((unsigned char)va_arg(arg, unsigned int));
	else if (lst->h)
		return ((unsigned short int)va_arg(arg, unsigned int));
	else if (lst->ll)
		return (va_arg(arg, unsigned long long int));
	else if (lst->l)
		return (va_arg(arg, unsigned long int));
	else if (lst->j)
		return (va_arg(arg, uintmax_t));
	else if (lst->z)
		return (va_arg(arg, size_t));
	return (va_arg(arg, unsigned int));
}
