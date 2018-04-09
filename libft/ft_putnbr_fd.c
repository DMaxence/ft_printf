/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:00:32 by maduhoux          #+#    #+#             */
/*   Updated: 2017/11/11 19:11:01 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_nbr(char *nbr, int fd)
{
	int i;

	i = 0;
	while (nbr[i] != 0)
	{
		ft_putchar_fd(nbr[i], fd);
		i++;
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n > 2147483647 || n < -2147483648)
	{
		return ;
	}
	if (n == -2147483648)
	{
		ft_print_nbr("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		n = n * -1;
		ft_putchar_fd('-', fd);
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
	return ;
}
