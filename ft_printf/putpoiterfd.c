/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpoiterfd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:03:10 by codespace         #+#    #+#             */
/*   Updated: 2024/01/18 22:09:38 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putpointerfd(void *ptr, char *base, int fd)
{
	char			buffer[18];
	unsigned long	address;
	int				i;
	int				digit;

	address = (unsigned long)ptr;

	i = 17;
	digit = 0;
	while (address != 0 && i >= 0)
	{
		digit = address % 16;
		buffer[i--] = base[digit];
		address /= 16;
	}
	if (!ptr)
		buffer[i--] = '0';
	buffer[i--] = 'x';
	buffer[i] = '0';
	write(fd, &buffer[i], 18 - i);
	return (18 - i);
}
