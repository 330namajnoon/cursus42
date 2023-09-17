/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:19:15 by simajnoo          #+#    #+#             */
/*   Updated: 2023/09/17 13:19:17 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char *ft_strdup(const char *s1)
{
    size_t i;
    char *s2;
    size_t len;

    i = -1;
    len = ft_strlen((char *)s1) + 1;
    s2 = (char *)calloc(len,sizeof(char));
    if(!s2)
        return (FT_NULL);
    while (++i < len - 1)
        s2[i] = s1[i];
    
    return (s2);
}
