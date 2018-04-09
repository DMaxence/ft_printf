/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:45:59 by maduhoux          #+#    #+#             */
/*   Updated: 2018/03/30 11:34:10 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbrbase(int nbr, char *char_base)
{
	if (nbr * -1 - 1 == 2147483647 || ft_strlen(char_base) > 32)
		return ;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		ft_putchar('-');
	}
	if (nbr / ft_strlen(char_base) != 0)
		ft_putnbrbase(nbr / ft_strlen(char_base), char_base);
	ft_putchar(char_base[nbr % ft_strlen(char_base)]);
}
