/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:10:12 by simajnoo          #+#    #+#             */
/*   Updated: 2023/11/26 18:23:09 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*newlist;
	void	*new_content;

	newlist = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		if (!new_content)
			return (ft_lstclear(&newlist, del), NULL);
		aux = ft_lstnew(new_content);
		if (!aux)
		{
			del(new_content);
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, aux);
		lst = lst -> next;
	}
	return (newlist);
}
