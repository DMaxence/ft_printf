/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 21:05:57 by maduhoux          #+#    #+#             */
/*   Updated: 2018/03/30 11:34:46 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_itoa_base(uintmax_t nb, int base, char c)
{
	int		i;
	char	*ret;
	char	*tmp_ret;

	i = 1;
	while (ft_power(base, i) - 1 < nb)
		i++;
	ret = ft_strnew(i);
	while (i-- > 0)
	{
		ret[i] = (nb % base) + (nb % base > 9 ? c - 10 : '0');
		nb /= base;
	}
	if (*ret == '0' && ret[1] != '\0')
	{
		tmp_ret = ret;
		while (*ret == '0')
			ret++;
		ret = ft_strdup(ret);
		free(tmp_ret);
	}
	return (ret);
}
