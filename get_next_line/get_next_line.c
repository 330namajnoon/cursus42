/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:44:20 by simajnoo          #+#    #+#             */
/*   Updated: 2025/01/14 09:16:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(t_data *data, t_vars *vars, int fd)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < BUFFER_SIZE)
			data->buffer[i] = 0;
		vars->b_read = read(fd, data->buffer, sizeof(data->buffer));
		if (vars->b_read)
		{
			if (!data->rest)
				data->rest = "";
			vars->cpy = ft_strjoin(data->rest, data->buffer);
			if (!vars->cpy)
				return (FT_NULL);
			if (data->rest && data->rest[0] != 0)
				free(data->rest);
			data->rest = vars->cpy;
		}
		if (data->rest)
		{
			vars->t = -1;
			vars->i = -1;
			while (data->rest[++vars->i])
				if (data->rest[vars->i] == '\n')
				{
					vars->t = vars->i + 1;
					break;
				}
			if (vars->t > -1)
			{
				if (vars->t + 1 < (int)ft_strlen(data->rest))
				{
					vars->res = ft_substr(data->rest, 0, vars->t);
					if (!vars->res)
						return (FT_NULL);
					vars->cpy = ft_substr(data->rest, vars->t, ft_strlen(data->rest) - vars->t);
				}
				else
				{
					vars->res = ft_substr(data->rest, 0, ft_strlen(data->rest));
					if (!vars->res)
						return (FT_NULL);
					free(data->rest);
					data->rest = FT_NULL;
					return (vars->res);
				}
				if (!vars->cpy)
					return (FT_NULL);
				if (data->rest)
					free(data->rest);
				data->rest = vars->cpy;
				return (vars->res);
			}
			else if (vars->b_read == 0)
			{
				vars->res = ft_substr(data->rest, 0, ft_strlen(data->rest));
				if (!vars->res)
					return (FT_NULL);
				free(data->rest);
				data->rest = FT_NULL;
				return (vars->res);
			}
		}
		else
			return (FT_NULL);
	}
}

char	*get_next_line(int fd)
{
	static t_data 	data;
	t_vars			vars;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		return (FT_NULL);
		if (data.rest)
			free(data.rest);
	}

	if (!get_line(&data, &vars, fd))
		return (FT_NULL);

	return (vars.res);
}