/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 21:06:39 by simajnoo          #+#    #+#             */
/*   Updated: 2025/01/13 16:35:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argn, char *argv[])
{
	int				file;
	char			*res;
	unsigned int	len;
	unsigned int	i;

	len = (unsigned int)atoi(argv[2]);
	file = open(argv[1], 0);
	i = -1;
	if (file == -1)
		return (0);
	while (++i < len)
	{
		res = get_next_line(file);
		if (!res)
			break ;
		printf("%s", res);
		free(res);
	}
	close(file);
	(void)argn;
	return (0);
}
