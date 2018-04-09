/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:18:09 by maduhoux          #+#    #+#             */
/*   Updated: 2018/04/06 16:30:26 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_char(t_flags *lst, va_list arg)
{
	int		ret;
	char	c;

	if (lst->l)
		return (ft_printf_char_upp(lst, arg));
	c = (char)va_arg(arg, int);
	ret = 1;
	ret = ft_printf_put_width(lst, ret, 0);
	if (c != '0' || lst->prec != 2)
		ft_putchar(c);
	ret = ft_printf_put_width(lst, ret, 1);
	return (ret);
}

int		ft_printf_str(t_flags *lst, va_list arg)
{
	int		ret;
	char	*str;
	int		length;

	if (lst->l)
		return (ft_printf_str_upp(lst, arg));
	str = va_arg(arg, char *);
	if (str == NULL)
		str = "(null)";
	length = ft_strlen(str);
	ret = length;
	ret = ft_printf_check_precision_string(lst, ret);
	ret = ft_printf_put_width(lst, ret, 0);
	if (lst->prec != 2)
	{
		write(1, str, (lst->precision > 0) ? lst->precision : length);
	}
	ret = ft_printf_put_width(lst, ret, 1);
	return (ret);
}

int		ft_printf_pourcent(t_flags *lst, va_list arg)
{
	int ret;

	(void)arg;
	ret = 1;
	while (lst->width > ret && !lst->minus)
	{
		ft_putchar(lst->zero ? '0' : ' ');
		ret++;
	}
	ft_putchar('%');
	while (lst->width > ret && lst->minus)
	{
		ft_putchar(' ');
		ret++;
	}
	return (ret);
}
