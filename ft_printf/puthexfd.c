/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthexfd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:48:42 by codespace         #+#    #+#             */
/*   Updated: 2024/01/16 12:52:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	puthexfd(unsigned int number, char *base, int fd)
{
	char	buffer[16];
	int		i;
	int		digit;

	i = 15;
	digit = 0;
	if (number == 0)
		return (write(fd, "0", 1));
	else
	{
		while (number != 0 && i >= 0)
		{
			digit = number % 16;
			buffer[i--] = base[digit];
			number /= 16;
		}
		write(fd, &buffer[i + 1], 15 - i);
	}
	return (15 - i);
}
