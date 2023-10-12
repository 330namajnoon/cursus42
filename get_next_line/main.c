/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 21:06:39 by simajnoo          #+#    #+#             */
/*   Updated: 2023/10/12 06:17:25 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argn, char *argv[])
{
	int	file;

	file = open("file.text", 0);
	if (file == -1)
		return (0);
	for (size_t i = 0; i < 10; i++)
	{
		/* code */
		printf("%s\n", get_next_line(file));
	}
	
	close(file);
	(void)argn;
	(void)argv;
	return (0);
}