/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbrbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 19:08:47 by maduhoux          #+#    #+#             */
/*   Updated: 2018/03/30 11:35:39 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putunbrbase(unsigned long int nbr, char *char_base)
{
	if (nbr * -1 - 1 == 2147483647 || ft_strlen(char_base) > 32)
		return ;
	if (nbr / ft_strlen(char_base) != 0)
		ft_putnbrbase(nbr / ft_strlen(char_base), char_base);
	ft_putchar(char_base[nbr % ft_strlen(char_base)]);
}
