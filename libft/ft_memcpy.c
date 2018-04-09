/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:31:07 by maduhoux          #+#    #+#             */
/*   Updated: 2017/11/13 21:03:36 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *a;
	unsigned char *b;

	a = (unsigned char *)src;
	b = (unsigned char *)dst;
	if (n == 0)
		return (dst);
	while (n > 0)
	{
		*b = *a;
		a++;
		b++;
		n--;
	}
	return (dst);
}
