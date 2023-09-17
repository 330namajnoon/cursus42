/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 00:53:37 by simajnoo          #+#    #+#             */
/*   Updated: 2023/09/15 00:56:41 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libc.h"
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = -1;
	len = 0;
	while(++i < dstsize && src[i])
		dst[i] = src[i];
	return(len);
}
