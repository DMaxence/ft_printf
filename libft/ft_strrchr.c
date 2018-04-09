/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:52:17 by maduhoux          #+#    #+#             */
/*   Updated: 2017/11/09 18:24:47 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *final;

	final = NULL;
	if ((char)c == '\0')
	{
		while (*s != '\0')
			s++;
		final = (char *)s;
		return (final);
	}
	while (*s != '\0')
	{
		if (*s == (char)c)
			final = (char *)s;
		s++;
	}
	return (final);
}
