/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:57:07 by simajnoo          #+#    #+#             */
/*   Updated: 2023/09/14 22:57:09 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libc.h"
void *ft_memcpy(void *dst, const void * src, size_t n)
{
    size_t i;
    char *d;
    char *s;

    d = (char*)dst;
    s = (char*)src;
    i = -1;
    while (++i < n && s[i])
        d[i] = s[i]; 
    return (d);
}
