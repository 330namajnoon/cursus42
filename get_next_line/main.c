/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 21:06:39 by simajnoo          #+#    #+#             */
/*   Updated: 2023/10/17 21:47:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argn, char *argv[])
{
	int		file;
	char	*res;

	file = open(argv[1], 0);
	if (file == -1)
		return (0);
	for (size_t i = 0; i < (unsigned int)atoi(argv[2]); i++)
	{
		res = get_next_line(file);
		if (!res)
			break;
		printf("%s", res);
		free(res);
	}
	close(file);
	(void)argn;
	(void)argv;
	return (0);
}