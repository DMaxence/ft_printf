/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:07:28 by maduhoux          #+#    #+#             */
/*   Updated: 2018/03/15 14:29:42 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t		ft_power(uintmax_t nb, int power)
{
	uintmax_t result;

	result = nb;
	power--;
	while (power--)
		result *= nb;
	return (result);
}
