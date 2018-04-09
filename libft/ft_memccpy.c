/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:08:22 by maduhoux          #+#    #+#             */
/*   Updated: 2017/11/13 21:04:00 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, \
	int c, size_t n)
{
	unsigned char *a;
	unsigned char *b;

	a = (unsigned char *)src;
	b = (unsigned char *)dst;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (*a == (unsigned char)c)
		{
			*b = *a;
			b++;
			return (b);
		}
		*b = *a;
		a++;
		b++;
		n--;
	}
	return (NULL);
}
