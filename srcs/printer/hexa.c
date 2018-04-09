/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:23:22 by maduhoux          #+#    #+#             */
/*   Updated: 2018/04/06 16:21:17 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_uhex_low(t_flags *lst, va_list arg)
{
	int		ret;
	char	*nb;
	int		put_x;

	ret = 0;
	nb = ft_printf_itoa_base(ft_printf_converter_unsigned(lst, arg), 16, 'a');
	ret = (nb[0] != '0' || lst->prec != 2) ? ret + ft_strlen(nb) : ret;
	ret = ft_printf_check_precision(lst, ret);
	put_x = ft_printf_put_x(lst, nb[0]);
	if (put_x > 0)
		ret += 2;
	if (put_x == 1)
		ft_putstr("0x");
	ret = ft_printf_put_width(lst, ret, 0);
	if (put_x == 2)
		ft_putstr("0x");
	while (lst->precision--)
		ft_putchar('0');
	if (nb[0] != '0' || lst->prec != 2)
		ft_putstr(nb);
	ret = ft_printf_put_width(lst, ret, 1);
	free(nb);
	return (ret);
}

int		ft_printf_uhex_upp(t_flags *lst, va_list arg)
{
	int		ret;
	char	*nb;
	int		put_x;

	ret = 0;
	nb = ft_printf_itoa_base(ft_printf_converter_unsigned(lst, arg), 16, 'A');
	ret = (nb[0] != '0' || lst->prec != 2) ? ret + ft_strlen(nb) : ret;
	ret = ft_printf_check_precision(lst, ret);
	put_x = ft_printf_put_x(lst, nb[0]);
	if (put_x > 0)
		ret += 2;
	if (put_x == 1)
		ft_putstr("0X");
	ret = ft_printf_put_width(lst, ret, 0);
	if (put_x == 2)
		ft_putstr("0X");
	while (lst->precision--)
		ft_putchar('0');
	if (nb[0] != '0' || lst->prec != 2)
		ft_putstr(nb);
	ret = ft_printf_put_width(lst, ret, 1);
	free(nb);
	return (ret);
}

int		ft_printf_ulp(t_flags *lst, va_list arg)
{
	int		ret;
	char	*nb;

	ret = 0;
	nb = ft_printf_itoa_base((uintmax_t)va_arg(arg, void *), 16, 'a');
	ret += (nb[0] != '0' || lst->prec != 2) ? ret + ft_strlen(nb) : ret;
	ret = ft_printf_check_precision(lst, ret);
	ret += 2;
	ret = ft_printf_put_width(lst, ret, 0);
	ft_putstr("0x");
	while (lst->precision--)
		ft_putchar('0');
	if (nb[0] != '0' || lst->prec != 2)
		ft_putstr(nb);
	ret = ft_printf_put_width(lst, ret, 1);
	free(nb);
	return (ret);
}
