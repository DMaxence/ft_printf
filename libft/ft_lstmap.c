/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 04:22:22 by maduhoux          #+#    #+#             */
/*   Updated: 2017/11/15 13:45:40 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*firstchain;

	if (!lst || !f)
		return (NULL);
	if (!(firstchain = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	ft_memcpy(firstchain, f(lst), sizeof(t_list));
	newlist = firstchain;
	while (lst->next)
	{
		lst = lst->next;
		if (!(newlist->next = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		ft_memcpy(newlist->next, f(lst), sizeof(t_list));
		newlist = newlist->next;
	}
	return (firstchain);
}

/*
** t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
** {
** 	t_list	*list;
** 	t_list	*newlist;
**
** 	if (!lst)
** 		return (NULL);
** 	list = f(lst);
** 	newlist = list;
** 	while (lst)
** 	{
** 		lst = lst->next;
** 		list->next = f(lst);
** 		list = list->next;
** 	}
** 	return (newlist);
** }
*/
