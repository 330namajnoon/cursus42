/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:13:23 by simajnoo          #+#    #+#             */
/*   Updated: 2023/11/26 21:35:41 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_num_rows(char *str, char c)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	if (ft_strncmp(str, "", 1) == 0)
		return (1);
	while (str[i] == c)
		i++;
	if (str[i] == 0)
		return (1);
	while (str[i])
	{
		if (str[i] == c)
		{
			while (str[i + 1] == c)
				i++;
			if (str[i + 1] != 0)
				num++;
		}
		i++;
	}
	return (num + 2);
}

void	*remove_table(char **table)
{
	int	i;

	i = -1;
	while (table[++i])
		free(table[i]);
	free(table);
	return (NULL);
}

int	get_start_end(char *s, char c, int ismax)
{
	int	i;

	if (ismax)
	{
		if (ft_strlen(s) == 0)
			return (0);
		i = ft_strlen(s) - 1;
		while (s[i] == c)
			i--;
		return (i + 1);
	}
	else
	{
		i = 0;
		while (s[i] == c)
			i++;
		return (i - 1);
	}
}

char	**set_table(char **table, char *s, char c)
{
	int	vs[3];

	vs[1] = 0;
	vs[2] = 0;
	vs[0] = get_start_end(s, c, 0);
	while (++vs[0] < get_start_end(s, c, 1))
	{
		if (s[vs[0]] == c)
		{
			table[vs[2]] = ft_substr(s, vs[0] - vs[1], vs[1]);
			if (!table[vs[2]])
				return (remove_table(table));
			vs[2]++;
			vs[1] = 0;
			while (s[vs[0] + 1] == c)
				vs[0]++;
		}
		else
			vs[1]++;
	}
	table[vs[2]] = ft_substr(s, vs[0] - vs[1], vs[1]);
	if (!table[vs[2]])
		return (remove_table(table));
	table[vs[2] + 1] = NULL;
	return (table);
}

char	**ft_split(char const *s, char c)
{
	char	**table;
	int		size;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	size = get_num_rows(str, c);
	table = (char **)ft_calloc(size, sizeof(char *));
	if (!table)
		return (NULL);
	if (size == 1)
	{
		table[0] = NULL;
		return (table);
	}
	return (set_table(table, (char *)str, c));
}
