/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:48:11 by maduhoux          #+#    #+#             */
/*   Updated: 2017/11/16 12:01:12 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dest[j])
		j++;
	while (i < nb && src[i])
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (dest);
}
