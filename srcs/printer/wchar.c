/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:40:04 by maduhoux          #+#    #+#             */
/*   Updated: 2018/04/06 15:10:30 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int			ft_printf_wcharlen(wchar_t c)
{
	if (c >= 0xd800 && c <= 0xdfff)
		return (-1);
	if (c < 0x7F)
		return (1);
	else if (c > 0x7F && c <= 0x7FF)
		return (2);
	else if (c > 0x7FF && c <= 0xFFFF)
		return (3);
	else if (c <= 0x10FFFF)
		return (4);
	return (-1);
}

int			ft_printf_check_wchar(wchar_t c)
{
	if (c >= 0xd800 && c <= 0xdfff)
		return (-1);
	return (0);
}

int			ft_printf_char_upp(t_flags *lst, va_list arg)
{
	wchar_t	c;
	int		ret;

	c = va_arg(arg, wchar_t);
	if ((ret = ft_printf_wcharlen(c)) == -1 || c < 0 || \
	ft_printf_check_wchar(c) == 1)
		return (-1);
	ret = ft_printf_put_width(lst, ret, 0);
	if (c != '0' || lst->prec != 2)
		ft_printf_putwchar(c);
	ret = ft_printf_put_width(lst, ret, 1);
	return (ret);
}

size_t		ft_wchar_strlen(const wchar_t *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			ft_printf_str_upp(t_flags *lst, va_list arg)
{
	wchar_t	*str;
	int		ret;
	int		length;
	int		count;
	int		i;

	str = va_arg(arg, wchar_t *);
	if (str == NULL)
		str = L"(null)";
	length = ft_wchar_strlen(str);
	ret = length;
	ret = ft_printf_check_precision_string(lst, ret);
	ret = ft_printf_put_width(lst, ret, 0);
	count = (lst->precision > 0) ? lst->precision : length;
	i = -1;
	if (lst->prec != 2)
		while (++i < count)
			ft_printf_putwchar(str[i]);
	ret = ft_printf_put_width(lst, ret, 1);
	return (ret);
}
