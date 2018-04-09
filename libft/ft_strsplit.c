/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:57:51 by maduhoux          #+#    #+#             */
/*   Updated: 2017/11/21 09:43:37 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_col_malloc(char **strsplit, char const *s, char c)
{
	int i;
	int column;

	i = 0;
	column = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (!s[i])
			break ;
		while (s[i] != c && s[i] != '\0')
			i++;
		column++;
	}
	if (!(strsplit = (char **)malloc(sizeof(char *) * (column + 1))))
		return (NULL);
	strsplit[column] = NULL;
	return (strsplit);
}

static char		**ft_line_malloc(char **strsplit, char const *s, char c)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (!s[i])
			break ;
		len = 0;
		while (s[i] != c && s[i] != '\0')
		{
			len++;
			i++;
		}
		if (!(strsplit[j] = (char *)malloc(sizeof(char) * (len + 2))))
			return (NULL);
		strsplit[j][len] = '\0';
		j++;
	}
	return (strsplit);
}

static char		**ft_strsplit_fill(char **strsplit, char const *s, char c)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (!s[i])
			break ;
		len = 0;
		while (s[i] != c && s[i] != '\0')
		{
			strsplit[j][len] = s[i];
			len++;
			i++;
		}
		j++;
	}
	strsplit[j] = NULL;
	return (strsplit);
}

char			**ft_strsplit(char const *s, char c)
{
	char **strsplit;

	if (!s)
		return (NULL);
	strsplit = 0;
	if (!(strsplit = ft_col_malloc(strsplit, s, c)))
		return (NULL);
	if (!(strsplit = ft_line_malloc(strsplit, s, c)))
		return (NULL);
	strsplit = ft_strsplit_fill(strsplit, s, c);
	return (strsplit);
}
