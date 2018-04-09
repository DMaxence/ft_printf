/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_octets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:05:33 by maduhoux          #+#    #+#             */
/*   Updated: 2018/04/06 15:10:15 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_one_o(char *tab, wchar_t c)
{
	tab[0] = (c >> 6) + 0xC0;
	tab[1] = (c & 0x3F) + 0x80;
	write(1, &tab[0], 1);
	write(1, &tab[1], 1);
	return (2);
}

int		ft_printf_two_o(char *tab, wchar_t c)
{
	tab[0] = (c >> 12) + 0xE0;
	tab[1] = ((c >> 6) & 0x3F) + 0x80;
	tab[2] = (c & 0x3F) + 0x80;
	write(1, &tab[0], 1);
	write(1, &tab[1], 1);
	write(1, &tab[2], 1);
	return (3);
}

int		ft_printf_three_o(char *tab, wchar_t c)
{
	tab[0] = (c >> 18) + 0xF0;
	tab[1] = ((c >> 12) & 0x3F) + 0x80;
	tab[2] = ((c >> 6) & 0x3F) + 0x80;
	tab[3] = (c & 0x3F) + 0x80;
	write(1, &tab[0], 1);
	write(1, &tab[1], 1);
	write(1, &tab[2], 1);
	write(1, &tab[3], 1);
	return (4);
}

int		ft_printf_putwchar(wchar_t c)
{
	char	tab[4];

	if (c >= 0xd800 && c <= 0xdfff)
		return (-1);
	if (c < 0x7F)
		return (write(1, &c, 1));
	else if (c > 0x7F && c <= 0x7FF)
		return (ft_printf_one_o(tab, c));
	else if (c > 0x7FF && c <= 0xFFFF)
		return (ft_printf_two_o(tab, c));
	else if (c <= 0x10FFFF)
		return (ft_printf_three_o(tab, c));
	return (-1);
}
