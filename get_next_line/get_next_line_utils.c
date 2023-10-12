/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 03:27:01 by simajnoo          #+#    #+#             */
/*   Updated: 2023/10/12 05:20:22 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (FT_NULL);
	list->content = content;
	list->next = FT_NULL;
	return (list);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*list;
	t_list	*lnext;

	list = *lst;
	while (list)
	{
		lnext = list->next;
		free(list->content);
		free(list);
		list = lnext;
	}
	*lst = FT_NULL;
}

char	*ft_strchr(const char *s, int c)
{
	if (c > 255)
		c = c % 256;
	while (1)
	{
		if (*s == c)
			return ((char *)s);
		if (*s == 0)
			return (FT_NULL);
		s++;
	}
	return (FT_NULL);
}