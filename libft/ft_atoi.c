/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:50:14 by simajnoo          #+#    #+#             */
/*   Updated: 2023/09/17 12:50:16 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi(const char *str)
{
    int res;
    int signo;

    res = 0;
    signo = 1;
    while (*str == ' ' || *str == '\t')
        str++;
    if(*str == '-')
    {
        signo = -1;
        str++;
    }
    else if(*str == '+')
        str++;
    while (*str != 0 && *str >= '0' && *str <= '9')
    {
        res = res * 10 + (*str - '0');
        str++;
    }
    return (res * signo);
}
