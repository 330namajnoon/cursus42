/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:01:23 by simajnoo          #+#    #+#             */
/*   Updated: 2023/09/22 22:13:05 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*lens(const char *s, char c)
{
	int	vars[6];
	int	*lens;

	vars[5] = 0;
	vars[0] = 1;
	vars[1] = 0;
	while (s[vars[1]] == c && s[vars[1]] != 0)
		vars[1]++;
	if (s[vars[1]] == 0)
		vars[5] = 1;
	while (s[vars[1]] != 0)
	{
		if (s[vars[1]] == c)
			vars[3] = 1;
		else if (vars[3] == 1)
		{
			while (s[vars[1]] == c)
				vars[1]++;
			vars[0]++;
			vars[3] = 0;
		}
		vars[1]++;
	}
	lens = (int *)calloc(vars[0] + 1, sizeof(int));
	if(vars[5])
		vars[0]--;
	if (!lens)
		return (FT_NULL);
	else
		lens[0] = vars[0];
	vars[1] = 0;
	vars[2] = 1;
	vars[3] = 0;
	vars[4] = 0;
	while (s[vars[1]] == c && s[vars[1]] != 0)
		vars[1]++;
	while (s[vars[1]] != 0)
	{
		if (s[vars[1]] == c)
			vars[3] = 1;
		else if(vars[3] == 1)
		{
			vars[2]++;
			vars[3] = 0;
		}
		if (vars[3] == 0)
			lens[vars[2]]++;
		vars[1]++;
	}
	return (lens);
}

void	setRes(char **res, int *len, int *vars, const char *s, char c)
{
	vars[0] = -1;
	vars[3] = 0;
	vars[1] = 0;
	while (s[vars[3]] == c)
		vars[3]++;
	while (++vars[1] <= len[0])
	{
		vars[2] = -1;
		res[++vars[0]] = (char *)malloc((len[vars[1]] + 1) * sizeof(char));
		while (++vars[2] < len[vars[1]])
			res[vars[0]][vars[2]] = s[vars[3]++];
		res[vars[0]][vars[2]] = 0;
		while (s[vars[3]] == c)
			vars[3]++;
	}
	res[++vars[0]] = FT_NULL;
	free(len);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		*len;
	int		vars[4];

	len = lens(s, c);
	if (!len)
		return (FT_NULL);
	res = (char **)malloc((len[0] + 1) * sizeof(char*));
	if (!res)
		return (FT_NULL);
	setRes(res, len, vars, s, c);
	return (res);
}

