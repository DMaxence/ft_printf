/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:25:33 by maduhoux          #+#    #+#             */
/*   Updated: 2017/12/06 15:41:47 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		compt;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	while ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t'))
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	j = ft_strlen(s) - 1;
	while ((s[j] == ' ') || (s[j] == '\n') || (s[j] == '\t'))
		j--;
	j++;
	compt = 0;
	if ((str = (char *)malloc(sizeof(char) * ((j - i) + 1))))
	{
		while (i < j)
			str[compt++] = s[i++];
		str[compt] = '\0';
	}
	return (str);
}
