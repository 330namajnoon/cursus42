/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:44:20 by simajnoo          #+#    #+#             */
/*   Updated: 2023/10/16 17:35:52 by codespace        ###   ########.fr       */
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

char	*reset_rest(int start, int end)
{
	int		i;
	char	*cpy;

	if (start > 0)
		cpy = (char *)malloc(end);
	else
	{
		free(data.rest);
		data.rest = (char *)malloc(1);
		if (!data.rest)
			return (FT_NULL);
		data.rest[0] = 0;
		return (data.rest);
	}
	if (!cpy)
		return (FT_NULL);
	i = 0;
	while ((data.rest)[++start])
	{
		cpy[i] = (data.rest)[start];
		i++;
	}
	cpy[i] = 0;
	free(data.rest);
	data.rest = cpy;
	return (data.rest);
}

char	*rest_to_res(char *res)
{
	int	pos;
	int	len;
	int	size;
	int	i;

	pos = 0;
	len = -1;
	while ((data.rest)[++len])
		if (!pos && (data.rest)[len] == '\n')
			pos = len;
	size = pos;
	if (!pos)
		size = ft_strlen(data.rest);
	res = (char *)malloc(size + 1);
	if (!res)
		return (FT_NULL);
	i = -1;
	while ((data.rest)[++i] != '\n' && data.rest[i])
		res[i] = (data.rest)[i];
	res[i] = 0;
	if (!reset_rest(pos, len))
		return (FT_NULL);
	return (res);
}

char	*get_next_line(int fd)
{
	char	*res;
	char	*cpy;
	int		b_read;
	int		t;

	(void)fd;
	res = "";
	if (!data.rest)
	{
		data.rest = (char *)malloc(1);
		if (!data.rest)
			return (FT_NULL);
		*(data.rest) = 0;
	}
	while (1)
	{
		b_read = read(fd, data.buffer, sizeof(data.buffer));
		if (b_read == -1)
		{
			free(data.rest);
			return (FT_NULL);
		}
		else if (b_read)
		{
			cpy = ft_strjoin(data.rest, data.buffer);
			free(data.rest);
			data.rest = cpy;
			t = -1;
			while ((data.rest)[++t])
			{
				if ((data.rest)[t] == '\n')
				{
					t = -1;
					break ;
				}
			}
			if (t == -1)
			{
				res = rest_to_res(res);
				if (!res)
					return (FT_NULL);
				break ;
			}
		}
		else
		{
			t = -1;
			while ((data.rest)[++t])
			{
				printf("_%d_\n", t);
				if ((data.rest)[t] == '\n')
				{
					t = -1;
					break ;
				}
			}
			if (t == -1 || !data.rest[t])
			{
				res = rest_to_res(res);
				if (!res)
					return (FT_NULL);
				break ;
			}
			break ;
		}
	}
	return (res);
}
