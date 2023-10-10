/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 02:12:07 by simajnoo          #+#    #+#             */
/*   Updated: 2023/10/09 23:31:52 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*list;

	list = lst;
	len = 0;
	if (lst)
	{
		len++;
		while (list->next)
		{
			len++;
			list = list->next;
		}
	}
	return (len);
}
