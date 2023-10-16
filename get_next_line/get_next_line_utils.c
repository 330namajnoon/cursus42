/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 03:27:01 by simajnoo          #+#    #+#             */
/*   Updated: 2023/10/16 14:01:57 by codespace        ###   ########.fr       */
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

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	unsigned int	varl[3];

	varl[1] = ft_strlen ((char *)s1);
	varl[2] = ft_strlen ((char *)s2);
	res = (char *)malloc ((varl[1] + varl[2] + 1) * sizeof (char));
	if (!res)
		return (FT_NULL);
	varl[0] = -1;
	while (++varl[0] < varl[1] + varl[2])
	{
		if (*s1 != 0)
		{
			res[varl[0]] = *s1;
			s1++;
		}
		else if (*s2 != 0)
		{
			res[varl[0]] = *s2;
			s2++;
		}
	}
	res[varl[0]] = 0;
	return (res);
}
