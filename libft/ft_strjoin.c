/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:16:58 by maduhoux          #+#    #+#             */
/*   Updated: 2017/11/13 10:25:09 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = -1;
	if ((ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + \
	ft_strlen(s2) + 1))))
	{
		while (s1[++j])
			ptr[j] = s1[j];
		while (s2[i])
			ptr[j++] = s2[i++];
		ptr[j] = '\0';
	}
	return (ptr);
}
