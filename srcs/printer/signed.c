/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:20:44 by maduhoux          #+#    #+#             */
/*   Updated: 2018/04/06 16:19:43 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_int(t_flags *lst, va_list arg)
{
	int			ret;
	intmax_t	nb_conv;
	char		*nb;
	int			negatif;

	ret = 0;
	nb_conv = ft_printf_converter_signed(lst, arg);
	lst->zero = (lst->minus > 0) ? 0 : lst->zero;
	negatif = 0;
	if (nb_conv < 0)
	{
		negatif = 1;
		nb_conv *= -1;
		ret = 1;
	}
	nb = ft_printf_itoa_base(nb_conv, 10, 'a');
	ret = (negatif == 1) ? ft_printf_i_neg(lst, nb, ret) : \
	ft_printf_i_pos(lst, nb, ret);
	free(nb);
	return (ret);
}

int		ft_printf_int_upp(t_flags *lst, va_list arg)
{
	int			ret;
	intmax_t	nb_conv;
	char		*nb;
	int			negatif;

	ret = 0;
	nb_conv = va_arg(arg, long int);
	lst->zero = (lst->minus > 0) ? 0 : lst->zero;
	negatif = 0;
	if (nb_conv < 0)
	{
		negatif = 1;
		nb_conv *= -1;
		ret = 1;
	}
	nb = ft_printf_itoa_base(nb_conv, 10, 'a');
	ret = (negatif == 1) ? ft_printf_i_neg(lst, nb, ret) : \
	ft_printf_i_pos(lst, nb, ret);
	free(nb);
	return (ret);
}

int		ft_printf_i_pos(t_flags *lst, char *nb, int ret)
{
	if (lst->plus || lst->space)
		lst->width--;
	ret = (nb[0] != '0' || lst->prec != 2) ? ret + ft_strlen(nb) : ret;
	ret = ft_printf_check_precision(lst, ret);
	if (lst->zero && lst->prec == 0)
		ft_printf_plusspace(lst);
	ret = ft_printf_put_width(lst, ret, 0);
	if (!lst->zero || (lst->zero && lst->prec))
		ft_printf_plusspace(lst);
	while (lst->precision--)
		ft_putchar('0');
	if (nb[0] != '0' || lst->prec != 2)
		ft_putstr(nb);
	ret = ft_printf_put_width(lst, ret, 1);
	ret = (lst->plus || lst->space) ? ret + 1 : ret;
	return (ret);
}

int		ft_printf_widthneg(t_flags *lst, int ret, int n, int length)
{
	int	width;

	width = lst->width - 1;
	if (lst->minus == n)
	{
		if (lst->precision > -1 && lst->precision > length)
			width -= lst->precision;
		else
			width -= length;
		while (width > 0)
		{
			ft_putchar((lst->zero) ? '0' : ' ');
			++ret;
			--width;
		}
	}
	return (ret);
}

int		ft_printf_i_neg(t_flags *lst, char *nb, int ret)
{
	int		length;
	int		precision;

	length = ft_strlen(nb);
	lst->zero = (lst->precision > 0) ? 0 : lst->zero;
	precision = lst->precision;
	ret += length;
	ret = (!lst->zero) ? ft_printf_widthneg(lst, ret, 0, length) : ret;
	ft_putchar('-');
	ret = (lst->zero && lst->width > 0) ? \
	ft_printf_widthneg(lst, ret, 0, length) : ret;
	while (precision-- > length)
	{
		ft_putchar('0');
		ret++;
	}
	ft_putstr(nb);
	ret = ft_printf_widthneg(lst, ret, 1, length);
	return (ret);
}
