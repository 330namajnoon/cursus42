/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:56:52 by simajnoo          #+#    #+#             */
/*   Updated: 2023/11/26 18:25:26 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (c > 255)
		c = c % 256;
	while (1)
	{
		if (*s == c)
			return ((char *)s);
		if (*s == 0)
			return (NULL);
		s++;
	}
	return (NULL);
}
