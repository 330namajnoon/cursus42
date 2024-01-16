/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:15:22 by simajnoo          #+#    #+#             */
/*   Updated: 2024/01/14 20:28:06 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putstrfd(char *str, int fd)
{
	int	i;

	i = -1;
	if (!str)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (str[++i])
		write(fd, &str[i], 1);
	return (i);
}