/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 14:29:05 by maduhoux          #+#    #+#             */
/*   Updated: 2018/04/06 14:32:14 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_bin(t_flags *lst, va_list arg)
{
	int		ret;
	char	*nb;

	nb = ft_printf_itoa_base(ft_printf_converter_unsigned(lst, arg), 2, 'a');
	ret = (nb[0] != '0' || lst->prec != 2) ? ft_strlen(nb) : 0;
	ret = ft_printf_check_precision(lst, ret);
	ret = ft_printf_put_width(lst, ret, 0);
	while (lst->precision--)
		ft_putchar('0');
	if (nb[0] != '0' || lst->prec != 2)
		ft_putstr(nb);
	ret = ft_printf_put_width(lst, ret, 1);
	free(nb);
	return (ret);
}
