/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:48:04 by maduhoux          #+#    #+#             */
/*   Updated: 2017/11/16 11:58:01 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int		i;
	char	temp;

	i = 0;
	while (src[i] != '\0')
	{
		temp = src[i];
		dest[i] = temp;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
