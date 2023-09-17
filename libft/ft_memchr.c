/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:36:28 by simajnoo          #+#    #+#             */
/*   Updated: 2023/09/17 15:53:44 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*ss;

	ss = (char *)s;
	while (*ss != 0 && n > 0)
	{
		if (*ss == c)
			return ((void *)ss);
		ss++;
		n--;
	}
	return (FT_NULL);
}
