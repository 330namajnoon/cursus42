/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:22:53 by simajnoo          #+#    #+#             */
/*   Updated: 2023/09/17 11:22:54 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    while (*s1 != 0 && *s1 == *s2 && n > 0)
    {
        s1++;
        s2++;
        n--;
    }

    return (*s1 - *s2);
}