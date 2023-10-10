/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:07:01 by simajnoo          #+#    #+#             */
/*   Updated: 2023/10/10 01:17:46 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argn, char *argv[])
{
	char	**res;
	int		i;

	res = ft_split(argv[1], argv[2][0]);
	i = -1;
	while (res[++i])
	{
		printf("%d : %s\n",i, res[i]);
		
	}
	printf("%ld %ld :: %s\n",sizeof(char *) * 3,sizeof(res), res[i]);
	i = -1;
	while (res[++i])
		free(res[i]);
	free(res);

	// char	*s;

	// s = ft_strnstr(argv[1], argv[2], ft_atoi(argv[3]));
	// printf("res: %s\n", s);
	// s = strnstr(argv[1], argv[2], ft_atoi(argv[3]));
	// printf("res1: %s\n", s);
	// bonus

	// t_list	*lst;

	// char	*str;
	// char	*str1;
	// char	*str2;

	// str = (char *)malloc(10);
	// str1 = (char *)malloc(10);
	// str2 = (char *)malloc(10);
	// str = ft_strdup("Hola");
	// str1 = ft_strdup("Mundo");
	// str2 = ft_strdup("qhe tal");
	// ft_lstadd_back(&lst, ft_lstnew(str));
	// ft_lstadd_back(&lst, ft_lstnew(str1));
	// ft_lstadd_back(&lst, ft_lstnew(str2));
	// ft_lstmap(lst, f, del);
	// free(str);
	(void)argn;
	(void)argv;
	return (0);
}
