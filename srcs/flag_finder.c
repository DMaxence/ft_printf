/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:15:23 by maduhoux          #+#    #+#             */
/*   Updated: 2018/01/23 17:15:53 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_diez_finder(char c, t_flags *lst)
{
	if (c == '#')
	{
		lst->diez = 1;
		return (1);
	}
	return (0);
}

int		ft_printf_zero_finder(char c, t_flags *lst)
{
	if (c == '0')
	{
		lst->zero = 1;
		return (1);
	}
	return (0);
}

int		ft_printf_plus_finder(char c, t_flags *lst)
{
	if (c == '+')
	{
		lst->plus = 1;
		return (1);
	}
	return (0);
}

int		ft_printf_minus_finder(char c, t_flags *lst)
{
	if (c == '-')
	{
		lst->minus = 1;
		return (1);
	}
	return (0);
}

int		ft_printf_space_finder(char c, t_flags *lst)
{
	if (c == ' ')
	{
		lst->space = 1;
		return (1);
	}
	return (0);
}
