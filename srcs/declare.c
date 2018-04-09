/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:40:37 by maduhoux          #+#    #+#             */
/*   Updated: 2018/04/06 14:31:10 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_declare_tab_conversion(void)
{
	char	*tab;

	if ((tab = (char *)malloc(sizeof(char) * 5)))
	{
		tab[0] = 'h';
		tab[1] = 'l';
		tab[2] = 'j';
		tab[3] = 'z';
		tab[4] = '\0';
	}
	return (tab);
}

char	*ft_printf_declare_tab_end(void)
{
	char	*tab;

	if ((tab = (char *)malloc(sizeof(char) * 17)))
	{
		tab[0] = 's';
		tab[1] = 'S';
		tab[2] = 'p';
		tab[3] = 'd';
		tab[4] = 'D';
		tab[5] = 'i';
		tab[6] = 'o';
		tab[7] = 'O';
		tab[8] = 'u';
		tab[9] = 'U';
		tab[10] = 'x';
		tab[11] = 'X';
		tab[12] = 'c';
		tab[13] = 'C';
		tab[14] = '%';
		tab[15] = 'b';
		tab[16] = '\0';
	}
	return (tab);
}

t_flags	ft_printf_lst_filler(void)
{
	t_flags lst;

	lst.diez = 0;
	lst.zero = 0;
	lst.minus = 0;
	lst.plus = 0;
	lst.space = 0;
	lst.width = 0;
	lst.precision = -1;
	lst.prec = 0;
	lst.j = 0;
	lst.z = 0;
	lst.hh = 0;
	lst.h = 0;
	lst.l = 0;
	lst.ll = 0;
	return (lst);
}
