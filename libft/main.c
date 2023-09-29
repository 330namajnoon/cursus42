/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:07:01 by simajnoo          #+#    #+#             */
/*   Updated: 2023/09/29 00:09:18 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del(void *c)
{
	(void)c;	
}
void	*f(void *c)
{
	return (c);
}

int	main(int argn, char *argv[])
{
	t_list	*lst;

	char	*str;
	char	*str1;
	char	*str2;

	str = (char *)malloc(10);
	str1 = (char *)malloc(10);
	str2 = (char *)malloc(10);
	str = ft_strdup("Hola");
	str1 = ft_strdup("Mundo");
	str2 = ft_strdup("qhe tal");
	ft_lstadd_back(&lst, ft_lstnew(str));
	ft_lstadd_back(&lst, ft_lstnew(str1));
	ft_lstadd_back(&lst, ft_lstnew(str2));
	ft_lstmap(lst, f, del);
	free(str);
	(void)argn;
	(void)argv;
	return (0);
}
