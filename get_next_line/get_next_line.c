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

char	*get_next_line(int fd)
{
	static t_data	data;
	t_vars			vars;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (FT_NULL);
	while (1)
	{
		vars.b_read = read(fd, data.buffer, sizeof(data.buffer));
		if (vars.b_read)
		{
			if (!data.rest)
				data.rest = ft_substr(data.buffer, 0, ft_strlen(data.buffer));
			else
				data.rest = ft_strjoin(data.rest, data.buffer);
		}
		if (data.rest)
		{
			vars.i = -1;
			vars.t = -1;
			while (data.rest[++vars.i])
			{
				if (data.rest[vars.i] == '\n' || data.rest[vars.i + 1] == '\0')
				{
					vars.t = vars.i;
					break ;
				}
			}
			if (vars.t != -1)
			{
				data.len = ft_strlen(data.rest);
				vars.res = ft_substr(data.rest, 0, vars.t + 1);
				vars.cpy = ft_substr(data.rest, vars.t + 1, data.len - vars.t);
				free(data.rest);
				data.rest = vars.cpy;
				return (vars.res);
			}
			else {
				free(data.rest);
				return (FT_NULL);
			}
		}
		
	}
}