/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:55:05 by simajnoo          #+#    #+#             */
/*   Updated: 2023/09/17 16:01:55 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*haystack1;
	int			i;

	i = 0;
	haystack1 = (char *)haystack;
	while (*haystack != 0 && len > 1)
	{
		while (*haystack == *needle && *needle != 0 && len > 1)
		{
			haystack++;
			needle++;
			len--;
			i++;
		}
		if (*needle == 0)
			return ((char *)haystack1);
		else if (i > 0)
			return (FT_NULL);
		len--;
		haystack1++;
		haystack++;
	}
	return (FT_NULL);
}
