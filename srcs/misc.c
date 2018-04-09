/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:17:01 by maduhoux          #+#    #+#             */
/*   Updated: 2018/04/06 16:30:13 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_check_precision(t_flags *lst, int ret)
{
	if (lst->precision > ret)
		lst->precision -= ret;
	else
		lst->precision = 0;
	ret += lst->precision;
	return (ret);
}

int		ft_printf_check_precision_string(t_flags *lst, int ret)
{
	if (lst->precision == -1)
		return (ret);
	if (lst->precision > ret)
		lst->precision = ret;
	if (lst->precision < ret)
		ret = lst->precision;
	return (ret);
}

int		ft_printf_put_width(t_flags *lst, int ret, int n)
{
	while (lst->width > ret && !lst->minus && n == 0)
	{
		ft_putchar(lst->zero && (!lst->prec || lst->prec == 2) ? '0' : ' ');
		ret++;
	}
	while (lst->width > ret && lst->minus && n == 1)
	{
		ft_putchar(' ');
		ret++;
	}
	return (ret);
}

void	ft_printf_plusspace(t_flags *lst)
{
	if (lst->plus)
		ft_putchar('+');
	else if (lst->space && !lst->plus)
		ft_putchar(' ');
}

int		ft_printf_put_x(t_flags *lst, char nb)
{
	if (lst->diez && nb != '0')
	{
		return ((lst->zero && !lst->prec) ? 1 : 2);
	}
	return (0);
}
