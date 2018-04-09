/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:25:09 by maduhoux          #+#    #+#             */
/*   Updated: 2018/04/06 14:30:38 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_tab(int (*tab[256])(t_flags *lst, va_list arg))
{
	tab['s'] = &ft_printf_str;
	tab['S'] = &ft_printf_str_upp;
	tab['p'] = &ft_printf_ulp;
	tab['d'] = &ft_printf_int;
	tab['D'] = &ft_printf_int_upp;
	tab['i'] = &ft_printf_int;
	tab['o'] = &ft_printf_uoctal;
	tab['O'] = &ft_printf_uoctal_upp;
	tab['u'] = &ft_printf_uint;
	tab['U'] = &ft_printf_uint_upp;
	tab['x'] = &ft_printf_uhex_low;
	tab['X'] = &ft_printf_uhex_upp;
	tab['c'] = &ft_printf_char;
	tab['C'] = &ft_printf_char_upp;
	tab['%'] = &ft_printf_pourcent;
	tab['b'] = &ft_printf_bin;
}

int		ft_printf_conversion_filler(char c, int size, t_flags *lst)
{
	if (c == 'h' && size == 2)
		lst->hh = 1;
	if (c == 'h' && size == 1)
		lst->h = 1;
	if (c == 'l' && size == 2)
		lst->ll = 1;
	if (c == 'l' && size == 1)
		lst->l = 1;
	if (c == 'j' && size == 1)
		lst->j = 1;
	if (c == 'z' && size == 1)
		lst->z = 1;
	return (0);
}
