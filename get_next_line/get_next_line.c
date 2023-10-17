/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:44:20 by simajnoo          #+#    #+#             */
/*   Updated: 2023/10/17 00:42:40 by codespace        ###   ########.fr       */
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

char	*rest_to_res(t_data data)
{
	
	
	return (FT_NULL);
}


char	*get_next_line(int fd)
{
	static t_data	data;
	t_vars vs;

	(void)fd;
	if (!data.rest)
	{
		data.rest = ft_strjoin("", "");
		if (!data.rest)
			return (FT_NULL);
	}
	while (1)
	{
		vs.b_read = read(fd, data.buffer, sizeof(data.buffer));
		if (vs.b_read)
		{
			// si b_read es mayor que 0, anade el buffer a data.rest
			vs.cpy = ft_strjoin(data.rest, data.buffer);
			if (!vs.cpy)
				return (FT_NULL);
			vs.t = -1;
			free(data.rest);
			data.rest = vs.cpy;
			// resetear buffer
			while (data.buffer[++vs.t])
				data.buffer[vs.t] = 0;
			// llamar a funcion rest_to_res por si hay alguna linea compeleta en data.rest, lo pone en variable rest.
			vs.t = -1;
			while (/* condition */)
			{
				/* code */
			}
			
			vs.res = rest_to_res(data);
			if (vs.res)
				break ;
		}
		else if (vs.b_read == 0)
		{
			break ;
		}
		else
		{
			break ;
		}
	}
	printf("%s", data.rest);
	return ("");
}
