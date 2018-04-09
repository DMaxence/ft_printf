/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 11:58:33 by maduhoux          #+#    #+#             */
/*   Updated: 2017/12/19 17:17:44 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_width(char c, t_flags *lst)
{
	if (c >= '0' && c <= '9')
	{
		lst->width++;
		return (1);
	}
	return (0);
}

int		ft_precision(int len, int precision)
{
	while (len < precision)
	{
		ft_putchar('0');
		len++;
	}
	return (0);
}
