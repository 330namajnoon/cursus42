/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:44:09 by simajnoo          #+#    #+#             */
/*   Updated: 2023/09/17 11:44:11 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const char *ss1;
    const char *ss2;

    ss1 = (char*)s1;
    ss2 = (char*)s2;
    while (*ss1 != 0 && *ss1 == *ss2 && n > 1)
    {
        ss1++;
        ss2++;
        n--;
    }
    return (*ss1 - *ss2);
}
