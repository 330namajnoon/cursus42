
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:13:23 by simajnoo          #+#    #+#             */
/*   Updated: 2023/10/10 03:11:03 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

struct	s_reslen {
	char	**res;
	int		*len;
};

void	set_vars(int *vars)
{
	vars[1] = 0;
	vars[2] = 1;
	vars[3] = 0;
	vars[4] = 0;
}

int	*set_lens(int *vars, int *lens, const char *s, char c)
{
	if (vars[5])
		vars[0]--;
	if (!lens)
		return (FT_NULL);
	else
		lens[0] = vars[0];
	set_vars(vars);
	while (s[vars[1]] == c && s[vars[1]] != 0)
		vars[1]++;
	while (s[vars[1]] != 0)
	{
		if (s[vars[1]] == c)
			vars[3] = 1;
		else if (vars[3] == 1)
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

int	*lens(int *vars, const char *s, char c)
{
	int	*lens;

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
	if (!set_lens(vars, lens, s, c))
		return (FT_NULL);
	return (lens);
}

void	set_res(struct s_reslen rl, int *vs, const char *s, char c)
{
	vs[0] = -1;
	vs[3] = 0;
	vs[1] = 0;
	while (s[vs[3]] == c)
		vs[3]++;
	while (++vs[1] <= rl.len[0])
	{
		vs[2] = -1;
		rl.res[++vs[0]] = (char *)malloc((rl.len[vs[1]] + 1) * sizeof(char));
		while (++vs[2] < rl.len[vs[1]])
			rl.res[vs[0]][vs[2]] = s[vs[3]++];
		rl.res[vs[0]][vs[2]] = 0;
		while (s[vs[3]] == c)
			vs[3]++;
	}
	rl.res[++vs[0]] = FT_NULL;
	free(rl.len);
}

char	**ft_split(char const *s, char c)
{
	struct s_reslen	res_len;
	int				vars[6];

	vars[5] = 0;
	vars[0] = 1;
	vars[1] = 0;
	res_len.len = lens(vars, s, c);
	if (!res_len.len)
		return (FT_NULL);
	res_len.res = (char **)malloc((res_len.len[0] + 1) * sizeof(char *));
	if (!res_len.res)
		return (FT_NULL);
	set_res(res_len, vars, s, c);
	return (res_len.res);
}