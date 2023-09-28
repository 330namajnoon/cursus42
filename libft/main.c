/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:07:01 by simajnoo          #+#    #+#             */
/*   Updated: 2023/09/26 16:55:19 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del(void *c)
{
	free(c);
}

int	main(int argn, char *argv[])
{
	char	*str;
	char	s[] = "tripouille";

	str = (char *)malloc(11);
	str = ft_strdup(s);
	printf("%s\n",ft_strrchr(str, 't' + 256));
	printf("%c\n",256);
	free(str);
	(void)argn;
	(void)argv;
	return (0);
}
