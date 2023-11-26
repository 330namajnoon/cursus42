/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 04:21:36 by simajnoo          #+#    #+#             */
/*   Updated: 2023/11/26 18:25:26 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	unsigned int	varl[3];

	varl[1] = ft_strlen ((char *)s1);
	varl[2] = ft_strlen ((char *)s2);
	res = (char *)malloc ((varl[1] + varl[2] + 1) * sizeof (char));
	if (!res)
		return (NULL);
	varl[0] = -1;
	while (++varl[0] < varl[1] + varl[2])
	{
		if (*s1 != 0)
		{
			res[varl[0]] = *s1;
			s1++;
		}
		else if (*s2 != 0)
		{
			res[varl[0]] = *s2;
			s2++;
		}
	}
	res[varl[0]] = 0;
	return (res);
}
