/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 18:11:08 by maduhoux          #+#    #+#             */
/*   Updated: 2017/12/02 18:16:20 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_realloc(char *src, size_t new_size)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	ft_strcpy(tmp, src);
	free(src);
	if (!(src = (char *)malloc(sizeof(char) * new_size)))
		return (NULL);
	src[new_size - 1] = '\0';
	ft_strcpy(src, tmp);
	free(tmp);
	return (src);
}
