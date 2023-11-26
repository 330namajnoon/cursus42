/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:27:03 by simajnoo          #+#    #+#             */
/*   Updated: 2023/11/26 18:25:26 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

struct s_resdata {
	int	start;
	int	end;
};

int	char_find(char c, char const *set)
{
	int	i;

	i = -1;
	while (set[++i] != 0)
	{
		if (set[i] == c)
			return (1);
	}
	return (0);
}

struct s_resdata	get_res_data(char const *str, char const *set)
{
	struct s_resdata	resdata;
	int					vars[1];

	vars[0] = -1;
	resdata.start = 0;
	while (str[++vars[0]] != 0 && char_find(str[vars[0]], set))
		resdata.start++;
	resdata.end = ft_strlen((char *)str);
	vars[0] = ft_strlen((char *)str);
	while (--vars[0] >= 0 && char_find(str[resdata.end - 1], set))
		resdata.end--;
	return (resdata);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char				*res;
	int					vars[2];
	struct s_resdata	resdata;

	resdata = get_res_data(s1, set);
	if (resdata.start >= resdata.end)
		return (ft_strdup(""));
	res = (char *)malloc(((resdata.end - resdata.start) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	vars[0] = resdata.start - 1;
	vars[1] = -1;
	while (++vars[0] < resdata.end)
		res[++vars[1]] = s1[vars[0]];
	res[++vars[1]] = 0;
	return (res);
}
