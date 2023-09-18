/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:12:28 by simajnoo          #+#    #+#             */
/*   Updated: 2023/09/17 16:02:44 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		cc;
	char	*ss;
	int		i;

	i = 1;
	cc = 0;
	ss = (char *)s;
	while (i)
	{
		if (*s == c)
		{
			ss = (char *)s;
			cc++;
		}
		if (*s == 0)
			i = 0;
		s++;
	}
	if (cc == 0)
		return ((void *)0);
	return ((char *)ss);
}
