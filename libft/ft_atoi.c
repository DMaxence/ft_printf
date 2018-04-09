/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:47:29 by maduhoux          #+#    #+#             */
/*   Updated: 2017/11/16 12:20:18 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_char(const char *str)
{
	int i;

	i = 0;
	while ((str[i] == ' ') || (str[i] == '\n') || (str[i] == '\t') ||
	(str[i] == '\r') || (str[i] == '\v') || (str[i] == '\f'))
		i++;
	return (i);
}

int				ft_atoi(const char *str)
{
	int i;
	int is_negative;
	int atoi;

	is_negative = 0;
	atoi = 0;
	i = ft_check_char(str);
	if (str[i] == '-')
	{
		is_negative = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		atoi = (atoi * 10) + (str[i] - '0');
		i++;
	}
	if (is_negative)
		return (atoi * -1);
	else
		return (atoi);
}
