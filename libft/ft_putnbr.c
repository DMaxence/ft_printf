/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:45:10 by maduhoux          #+#    #+#             */
/*   Updated: 2017/11/11 19:11:20 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_nbr(char *nbr)
{
	int i;

	i = 0;
	while (nbr[i] != 0)
	{
		ft_putchar(nbr[i]);
		i++;
	}
}

void		ft_putnbr(int nb)
{
	if (nb > 2147483647 || nb < -2147483648)
	{
		return ;
	}
	if (nb == -2147483648)
	{
		ft_print_nbr("-2147483648");
		return ;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-');
	}
	if (nb < 10)
	{
		ft_putchar(nb + '0');
		return ;
	}
	ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
	return ;
}
