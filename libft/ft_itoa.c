/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:21:23 by maduhoux          #+#    #+#             */
/*   Updated: 2017/11/13 17:31:38 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_count(int n)
{
	int i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa_fill(char *itoa, unsigned int n, int count)
{
	while (n != 0)
	{
		itoa[count] = (n % 10) + '0';
		n /= 10;
		count--;
	}
	return (itoa);
}

char		*ft_itoa(int n)
{
	int				i;
	int				count;
	unsigned int	nbis;
	char			*itoa;

	count = ft_int_count(n);
	if (!(itoa = ft_strnew(count)))
		return (NULL);
	i = 0;
	nbis = n;
	if (n < 0)
	{
		if (!(itoa = ft_strnew(count)))
			return (NULL);
		itoa[0] = '-';
		nbis = ((n + 1) * -1) + 1;
	}
	else if (n == 0)
		itoa[0] = '0';
	return (ft_itoa_fill(itoa, nbis, count - 1));
}
