/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:24:05 by maduhoux          #+#    #+#             */
/*   Updated: 2018/03/30 16:23:26 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_uoctal(t_flags *lst, va_list arg)
{
	int		ret;
	char	*nb;

	nb = ft_printf_itoa_base(ft_printf_converter_unsigned(lst, arg), 8, 'a');
	ret = (nb[0] != '0' || lst->prec != 2) ? ft_strlen(nb) : 0;
	ret = ft_printf_check_precision(lst, ret);
	if ((lst->diez && lst->precision == 0 && nb[0] != '0') || (lst->diez && \
	lst->prec == 2 && nb[0] == '0'))
		ret++;
	ret = ft_printf_put_width(lst, ret, 0);
	if ((lst->diez && lst->precision == 0 && nb[0] != '0') || (lst->diez && \
	lst->prec == 2 && nb[0] == '0'))
		ft_putstr("0");
	while (lst->precision--)
		ft_putchar('0');
	if (nb[0] != '0' || lst->prec != 2)
		ft_putstr(nb);
	ret = ft_printf_put_width(lst, ret, 1);
	free(nb);
	return (ret);
}

int		ft_printf_uoctal_upp(t_flags *lst, va_list arg)
{
	int		ret;
	char	*nb;

	nb = ft_printf_itoa_base(va_arg(arg, long unsigned int), 8, 'a');
	ret = (nb[0] != '0' || lst->prec != 2) ? ft_strlen(nb) : 0;
	ret = ft_printf_check_precision(lst, ret);
	if ((lst->diez && lst->precision == 0 && nb[0] != '0') || (lst->diez && \
	lst->prec == 2 && nb[0] == '0'))
		ret++;
	ret = ft_printf_put_width(lst, ret, 0);
	if ((lst->diez && lst->precision == 0 && nb[0] != '0') || (lst->diez && \
	lst->prec == 2 && nb[0] == '0'))
		ft_putstr("0");
	while (lst->precision--)
		ft_putchar('0');
	if (nb[0] != '0' || lst->prec != 2)
		ft_putstr(nb);
	ret = ft_printf_put_width(lst, ret, 1);
	free(nb);
	return (ret);
}
