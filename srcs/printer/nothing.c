/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nothing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:14:05 by maduhoux          #+#    #+#             */
/*   Updated: 2018/04/06 16:17:45 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_nothing(t_flags *lst)
{
	int		ret;

	ret = 0;
	lst->width--;
	ret = ft_printf_put_width(lst, ret, 0);
	ret = ft_printf_put_width(lst, ret, 1);
	return (ret);
}
