/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:44:20 by simajnoo          #+#    #+#             */
/*   Updated: 2023/10/17 23:11:58 by codespace        ###   ########.fr       */
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

char	*rest_to_res(t_data *data,unsigned int pos)
{
	char	*res;
	char	*rest;

	res = ft_substr(data->rest, 0, pos + 1);
	rest = ft_substr(data->rest, pos + 1, ft_strlen(data->rest) - 1);
	if (!res && rest)
	{
		free(rest);
		return (FT_NULL);
	}
	else if (!rest && res)
	{
		free(res);
		return (FT_NULL);
	}
	free(data->rest);
	data->rest = rest;
	return (res);
}


char	*get_next_line(int fd)
{
	static t_data	data;
	t_vars vs;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (FT_NULL);
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
			free(data.rest);
			data.rest = vs.cpy;
			// resetear buffer
			vs.t = -1;
			while (data.buffer[++vs.t])
				data.buffer[vs.t] = 0;
			// llamar a funcion rest_to_res por si hay alguna linea compeleta en data.rest, lo pone en variable rest.
			vs.t = -1;
			vs.i = -1;
			while (data.rest[++vs.i])
			{
				if (data.rest[vs.i] == '\n')
				{
					vs.t = vs.i;
					break ;
				}
			}
			// si vs.t es igual que 0 significa que no hay un \n en data.rest y tiene que volver a rellenar buffer otra vez hasta que tenga un \n.
			// y si es mayor que 0 llama a funcion rest_to rest.
			if (vs.t != -1)
			{
				vs.res = rest_to_res(&data, vs.t);
				if (!vs.res)
					return (FT_NULL);
				break ;
			}
		}
		else if (vs.b_read == 0)
		{
			if (!*data.rest)
				return (free(data.rest), FT_NULL);
			// llamar a funcion rest_to_res por si hay alguna linea compeleta en data.rest, lo pone en variable rest.
			vs.t = -1;
			vs.i = -1;
			while (data.rest[++vs.i])
			{
				if (data.rest[vs.i] == '\n')
				{
					vs.t = vs.i;
					break ;
				}
			}
			// si vs.t es igual que 0 significa que no hay un \n en data.rest y tiene que volver a rellenar buffer otra vez hasta que tenga un \n.
			// y si es mayor que 0 llama a funcion rest_to rest.
			if (vs.t != -1)
			{
				vs.res = rest_to_res(&data, vs.t);
				if (!vs.res)
					return (FT_NULL);
				break ;
			}
			else
			{
				vs.res = rest_to_res(&data, ft_strlen(data.rest));
				if (!vs.res)
					return (FT_NULL);
				break ;
			}
			break ;
		}
		else
		{
			if (data.rest)
				free(data.rest);
			return (FT_NULL);
		}
	}
	return (vs.res);
}
