/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 05:35:18 by simajnoo          #+#    #+#             */
/*   Updated: 2023/09/26 15:59:49 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*lnext;

	list = *lst;
	while (list)
	{
		lnext = list->next;
		del(list->content);
		free(list);
		list = lnext;
	}
	*lst = FT_NULL;
}
