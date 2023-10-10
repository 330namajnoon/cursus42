/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:01:23 by simajnoo          #+#    #+#             */
/*   Updated: 2023/09/24 03:21:20 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

struct		s_get_list_vars
{
	int		i;
	int		j;
	int		start;
	int		end;
	t_list	*list;
	t_list	*newlist;
	char	*strsub;
};

void	del(void *val)
{
	free(val);
}

t_list	*get_list(char const *s, char c)
{
	struct s_get_list_vars	vs;

	vs.list = FT_NULL;
	vs.i = 0;
	while (s[vs.i] != 0 && s[vs.i] == c)
		vs.i++;
	vs.start = vs.i;
	while (s[vs.i] != 0)
	{
		vs.j = 0;
		while (s[vs.i] == c)
		{
			if (vs.j == 0)
				vs.end = vs.i - vs.start;
			vs.j++;
			vs.i++;
		}
		if (vs.j > 0)
		{
			vs.strsub = ft_substr(s, vs.start, vs.end);
			if (!vs.strsub)
				return (FT_NULL);
			vs.newlist = ft_lstnew(vs.strsub);
			if (!vs.newlist)
				return (FT_NULL);
			ft_lstadd_back(&vs.list, vs.newlist);
			vs.start = vs.i;
		}
		if (s[vs.i] != 0)
			vs.i++;
	}
	vs.strsub = ft_substr(s, vs.start, vs.i - vs.start);
	if (!vs.strsub)
		return (FT_NULL);
	vs.newlist = ft_lstnew(vs.strsub);
	if (!vs.newlist)
		return (FT_NULL);
	ft_lstadd_back(&vs.list, vs.newlist);
	return (vs.list);
}

void	*ft_free(char **s)
{
	int	i;

	i = -1;
	while (s[++i] != 0)
		free(s[i]);
	free(s);
	return (FT_NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		res_len;
	int		i;
	t_list	*list;
	t_list	*list_;

	list = get_list(s, c);
	if (!list)
		return (FT_NULL);
	list_ = list;
	res_len = ft_lstsize(list) + 1;
	if (!ft_strlen((char *)list_->content))
		res_len = 1;
	res = (char **)malloc((res_len) * sizeof(char *));
	if (!res)
		return (FT_NULL);
	i = 0;
	while (list_ && ft_strlen((char *)list_->content))
	{
		res[i] = ft_strdup(list_->content);
		if (!res[i])
			return (ft_free(res));
		list_ = list_->next;
		i++;
	}
	ft_lstclear(&list, del);
	free(list);
	res[i] = FT_NULL;
	return (res);
}