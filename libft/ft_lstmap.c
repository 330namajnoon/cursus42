/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:10:12 by simajnoo          #+#    #+#             */
/*   Updated: 2023/09/26 16:21:04 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*list;

	list = lst;
	while (list)
	{
		newlist = list;
		newlist->content = f(lst->content);
		if (!newlist->content)
		{
			ft_lstclear(&lst, del);
			return (newlist);
		}
		list = list->next;
	}
	return (newlist);
}
