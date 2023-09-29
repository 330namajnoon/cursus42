/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:10:12 by simajnoo          #+#    #+#             */
/*   Updated: 2023/09/29 00:15:31 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;

	(void)f;
	(void)del;
	while (lst)
	{
		newlist = f(lst->content);
		if (!newlist)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&newlist, del);
		}
		newlist = newlist->next;
		lst = lst->next;
	}
	return (newlist);
}
