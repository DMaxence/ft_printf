/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:50:23 by maduhoux          #+#    #+#             */
/*   Updated: 2017/11/13 10:24:34 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	str = NULL;
	if ((str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
	{
		while (s[i])
		{
			str[i] = f((char)s[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
