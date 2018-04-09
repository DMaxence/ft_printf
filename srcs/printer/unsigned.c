/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:25:02 by maduhoux          #+#    #+#             */
/*   Updated: 2018/03/30 13:25:04 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_uint(t_flags *lst, va_list arg)
{
	int		ret;
	char	*nb;

	ret = 0;
	nb = ft_printf_itoa_base(ft_printf_converter_unsigned(lst, arg), 10, 'a');
	if (lst->prec == 2 && *nb == '0')
		return (0);
	ret += ft_strlen(nb);
	ret = ft_printf_check_precision(lst, ret);
	ret = ft_printf_put_width(lst, ret, 0);
	while (lst->precision--)
		ft_putchar('0');
	ft_putstr(nb);
	ret = ft_printf_put_width(lst, ret, 1);
	free(nb);
	return (ret);
}

int		ft_printf_uint_upp(t_flags *lst, va_list arg)
{
	int		ret;
	char	*nb;

	ret = 0;
	nb = ft_printf_itoa_base(va_arg(arg, long unsigned int), 10, 'a');
	if (lst->prec == 2 && *nb == '0')
		return (0);
	ret += ft_strlen(nb);
	ret = ft_printf_check_precision(lst, ret);
	ret = ft_printf_put_width(lst, ret, 0);
	while (lst->precision--)
		ft_putchar('0');
	ft_putstr(nb);
	ret = ft_printf_put_width(lst, ret, 1);
	free(nb);
	return (ret);
}
