/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:51:12 by maduhoux          #+#    #+#             */
/*   Updated: 2017/11/13 10:24:23 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if ((str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
	{
		while (s[i])
		{
			str[i] = f(i, (char)s[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
