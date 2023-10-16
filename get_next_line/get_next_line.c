/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:44:20 by simajnoo          #+#    #+#             */
/*   Updated: 2023/10/16 23:48:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static struct	s_data	data;

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
	int	b_read;
	int t;
	(void)fd;
	if (!data.rest)
	{
		data.rest = ft_strjoin("", "");
		if (!data.rest)
			return (FT_NULL);
	}
	while (1)
	{
		b_read = read(fd, data.buffer, sizeof(data.buffer));
		if (b_read)
		{
			printf("\n:%s:\n", data.buffer);
			t = -1;
			while (data.buffer[++t])
				data.buffer[t] = 0;
		}
		else if (b_read == 0)
		{
			break ;
		}
		else
		{
			break ;
		}
	}
	
	return ("");
}
