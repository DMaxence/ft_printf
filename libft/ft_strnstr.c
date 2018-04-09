/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:14:17 by maduhoux          #+#    #+#             */
/*   Updated: 2017/11/11 12:51:14 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int	i;
	int j;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < (int)len)
	{
		j = 0;
		while (to_find[j] == str[j + i] && (i + j) < (int)len)
		{
			if (to_find[j + 1] == '\0' && i < (int)len)
				return ((char *)&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}
