/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 11:45:31 by maduhoux          #+#    #+#             */
/*   Updated: 2018/03/30 17:24:28 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_printf_flags_parser(const char **format, t_flags *lst)
{
	while (ft_printf_parse_flag(**format, lst))
		*format += 1;
	while (**format >= '0' && **format <= '9' \
	&& **format && !ft_printf_check_end(**format))
	{
		lst->width = (lst->width * 10) + (**format - '0');
		*format += 1;
	}
	if (**format == '.')
	{
		*format += 1;
		lst->precision = 0;
		while (**format >= '0' && **format <= '9' && **format && \
		!ft_printf_check_end(**format))
		{
			lst->precision = (lst->precision * 10) + (**format - '0');
			*format += 1;
		}
		lst->prec = (lst->precision == 0) ? 2 : 1;
	}
	if (ft_printf_check_conversion(**format) && **format)
		ft_printf_parser_utils(format, lst);
	*format -= 1;
	return (*lst);
}

void	ft_printf_parser_utils(const char **format, t_flags *lst)
{
	*format += 1;
	if (ft_printf_check_conversion(**format))
	{
		ft_printf_conversion_filler(**format, 2, lst);
		*format += 1;
	}
	else
		ft_printf_conversion_filler(*(*format - 1), 1, lst);
}

int		ft_printf_parse_flag(char c, t_flags *lst)
{
	if (ft_printf_diez_finder(c, lst))
		return (1);
	if (ft_printf_zero_finder(c, lst))
		return (1);
	if (ft_printf_plus_finder(c, lst))
		return (1);
	if (ft_printf_minus_finder(c, lst))
		return (1);
	if (ft_printf_space_finder(c, lst))
		return (1);
	return (0);
}
