/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 04:18:12 by simajnoo          #+#    #+#             */
/*   Updated: 2023/09/24 04:40:15 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (FT_NULL);
	i = -1;
	if (s[0] != 0)
	{
		while (++i < len && s[start] != 0 && start < ft_strlen((char *)s))
		{
			res[i] = s[start];
			start++;
		}
	}
	res[i] = 0;
	return (res);
}
