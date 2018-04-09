/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:22:18 by maduhoux          #+#    #+#             */
/*   Updated: 2018/04/06 14:31:16 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_check_end(char c)
{
	int		i;
	char	*tab;

	i = 0;
	tab = ft_printf_declare_tab_end();
	while (i < 16)
	{
		if (c == tab[i])
		{
			free(tab);
			return (1);
		}
		i++;
	}
	free(tab);
	return (0);
}

int		ft_printf_check_conversion(char c)
{
	int		i;
	char	*tab;

	i = 0;
	tab = ft_printf_declare_tab_conversion();
	while (i < 5)
	{
		if (c == tab[i])
		{
			free(tab);
			return (1);
		}
		i++;
	}
	free(tab);
	return (0);
}
