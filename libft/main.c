/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:07:01 by simajnoo          #+#    #+#             */
/*   Updated: 2023/09/24 03:36:18 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argn, char *argv[])
{
	int i = -1;
	char	**dst;

	dst = ft_split(argv[1], argv[2][0]);
	i = -1;
	printf("%d\n",dst[2] == FT_NULL);
	printf("%d\n",ft_memcmp(dst[0], "sina", 4));
	
	//printf("%s\n",dst[0]);
	while (dst[++i] != FT_NULL)
	{
		printf("%s\n",dst[i]);
	}
	i = -1;
	while (dst[++i] != FT_NULL)
	{
		free(dst[i]);
	}
	free(dst);

	(void)argn;

	return (0);
}
