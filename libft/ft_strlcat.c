/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 01:01:28 by simajnoo          #+#    #+#             */
/*   Updated: 2023/09/15 01:01:33 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"


size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t  i;
    size_t  len;

    i = -1;
    len = ft_strlen(dst) - 1;
    while(++i < dstsize && dst[i])
        dst[++len] = src[i];
    return (len);
}