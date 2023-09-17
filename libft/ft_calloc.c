/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:06:01 by simajnoo          #+#    #+#             */
/*   Updated: 2023/09/17 13:06:04 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
    int *src;
    size_t i;

    i = -1;
    src = (int *)malloc(count * size);
    if(!src)
        return (FT_NULL);
    while (++i < count)
        src[i] = 0;
    return ((void*)src);
}
