/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:44:20 by simajnoo          #+#    #+#             */
/*   Updated: 2023/10/12 06:22:44 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s2;
	size_t	len;

	i = -1;
	len = 1;
	while (s1[++i])
		len++;
	i = -1;
	s2 = (char *)malloc(len * sizeof(char));
	if (!s2)
		return (FT_NULL);
	while (++i < len - 1)
		s2[i] = s1[i];
	s2[i] = 0;
	return (s2);
}

char	*get_next_line(int fd)
{
	char		*res;
	ssize_t		b_read;
	t_list		*list;
	t_list		*newlist;
	char		*content;
	size_t		t;

	t = 1;
	list = FT_NULL;
	if (data.rest)
	{
		newlist = ft_lstnew(data.rest);
		if (!newlist)
		{
			ft_lstclear(&list);
			return (FT_NULL);
		}
		ft_lstadd_back(&list, newlist);
	}
	while (t)
	{
		b_read = read(fd, data.buffer, sizeof(data.buffer));
		content = ft_strdup(data.buffer);
		if (!content)
		{
			ft_lstclear(&list);
			return (FT_NULL);
		}
		newlist = ft_lstnew(content);
		if (!newlist)
		{
			ft_lstclear(&list);
			return (FT_NULL);
		}
		ft_lstadd_back(&list, newlist);
		if (ft_strchr(data.buffer, '\n'))
		{
			t = 0;
			while (content[t] != '\n')
				t++;
			data.rest = &content[t+1];
			t = 0;
		}
	}
	newlist = list;
	data.len = 0;
	while (newlist)
	{
		t = 0;
		while (((char *)newlist->content)[t] != '\n' &&
			((char *)newlist->content)[t] != 0)
		{
			t++;
			data.len++;
		}
		newlist = newlist->next;
	}
	res = (char *)malloc(data.len + 1);
	newlist = list;
	data.len = -1;
	while (newlist)
	{
		t = 0;
		while (((char *)newlist->content)[t] != '\n' &&
			((char *)newlist->content)[t] != 0)
		{
			res[++data.len] = ((char *)newlist->content)[t];
			t++;
		}
		newlist = newlist->next;
	}
	res[data.len+1] = 0;
	ft_lstclear(&newlist);
	return (res);
}
