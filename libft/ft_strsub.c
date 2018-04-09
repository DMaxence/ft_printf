/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:01:17 by maduhoux          #+#    #+#             */
/*   Updated: 2017/11/13 10:25:34 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if ((ptr = (char *)malloc(sizeof(char) * (len + 1))))
	{
		while (i < len)
			ptr[i++] = s[start++];
		ptr[i] = '\0';
	}
	return (ptr);
}
