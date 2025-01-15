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

char	*join_readed_to_rest(t_data *data, t_vars *vars, int fd)
{
	int	i;

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
			return (NULL);
		if (data->rest && data->rest[0] != 0)
			free(data->rest);
		data->rest = vars->cpy;
	}
	return (data->rest);
}

char	*create_line(t_data *data, t_vars *vars)
{
	if (vars->t + 1 < (int)ft_strlen(data->rest))
	{
		vars->res = ft_substr(data->rest, 0, vars->t);
		if (!vars->res)
			return (NULL);
		data->len = ft_strlen(data->rest) - vars->t;
		vars->cpy = ft_substr(data->rest, vars->t, data->len);
	}
	else
	{
		vars->res = ft_substr(data->rest, 0, ft_strlen(data->rest));
		if (!vars->res)
			return (NULL);
		free(data->rest);
		data->rest = NULL;
		return (vars->res);
	}
	if (!vars->cpy)
		return (NULL);
	if (data->rest)
		free(data->rest);
	data->rest = vars->cpy;
	return (vars->res);
}

char	*fix_rest(t_data *data, t_vars *vars)
{
	vars->res = ft_substr(data->rest, 0, ft_strlen(data->rest));
	if (!vars->res)
		return (NULL);
	free(data->rest);
	data->rest = NULL;
	return (vars->res);
}

char	*my_get_line(t_data *data, t_vars *vars, int fd)
{
	while (1)
	{
		if (!join_readed_to_rest(data, vars, fd))
			return (NULL);
		if (data->rest)
		{
			vars->t = -1;
			vars->i = -1;
			while (data->rest[++vars->i])
			{
				if (data->rest[vars->i] == '\n')
				{
					vars->t = vars->i + 1;
					break ;
				}
			}
			if (vars->t > -1)
				return (create_line(data, vars));
			else if (vars->b_read == 0)
				return (fix_rest(data, vars));
		}
		else
			return (NULL);
	}
}

char	*get_next_line(int fd)
{
	static t_data	data;
	t_vars			vars;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (data.rest)
			free(data.rest);
		return (NULL);
	}
	if (!my_get_line(&data, &vars, fd))
		return (NULL);
	return (vars.res);
}
