/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpoiterfd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:03:10 by codespace         #+#    #+#             */
/*   Updated: 2024/01/16 12:08:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putpointerfd(void *ptr, char *base, int fd)
{
	char			buffer[16];
	unsigned long	address;
	int				i;
	int				digit;

	address = (unsigned long)ptr;
	i = 15;
	digit = 0;
	if (!ptr)
		return (write(fd, "(nil)", 5));
	while (address != 0 && i >= 0)
	{
		digit = address % 16;
		buffer[i--] = base[digit];
		address /= 16;
	}
	buffer[i--] = 'x';
	buffer[i] = '0';
	write(fd, &buffer[i], 16 - i);
	return (16 - i);
}
