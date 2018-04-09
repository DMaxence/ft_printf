/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:37:03 by maduhoux          #+#    #+#             */
/*   Updated: 2017/11/15 14:28:39 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int len;

	if (!s || !f)
		return ;
	len = 0;
	while (len < (unsigned int)ft_strlen(s))
	{
		f(len, s + len);
		len++;
	}
}
