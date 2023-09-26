/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:07:01 by simajnoo          #+#    #+#             */
/*   Updated: 2023/09/26 05:55:54 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del(void *c)
{
	free(c);
}

int	main(int argn, char *argv[])
{
	t_list	*list;

	char *str = (char *)malloc(10);
	char *str1 = (char *)malloc(10);
	char *str2 = (char *)malloc(10);
	str = strcpy(str, "mundo");
	str1 = strcpy(str1, "que tal");
	str2 = strcpy(str2, "chicos");
	ft_lstadd_back(&list, ft_lstnew(str));
	ft_lstadd_back(&list, ft_lstnew(str1));
	ft_lstadd_back(&list, ft_lstnew(str2));
	ft_lstclear(&list, del);
	printf("%s\n",list->content);
	printf("%s\n",list->next->content);
	printf("%s\n",list->next->next->content);
	(void)argn;
	(void)argv;
	return (0);
}
