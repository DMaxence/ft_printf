/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:55:25 by maduhoux          #+#    #+#             */
/*   Updated: 2017/11/16 12:07:17 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		i;

	i = -1;
	if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	while (src[++i])
		str[i] = src[i];
	str[i] = 0;
	return (str);
}
