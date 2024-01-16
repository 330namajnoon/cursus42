/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbrfd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:20:12 by simajnoo          #+#    #+#             */
/*   Updated: 2024/01/14 20:28:33 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	special(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	return (0);
}

int	check_negative(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		return (-1);
	}
	return (1);
}

int	num_len(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	putnbrfd(int n, int fd)
{
	int		i;
	int		len;
	char	num[11];
	int		sign;

	i = 0;
	len = special(n, fd);
	if (len)
		return (len);
	sign = check_negative(n, fd);
	n = n * sign;
	len += num_len(n);
	i = len - 1;
	while (i >= 0)
	{
		num[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	if (sign < 0)
		return (write(fd, num, len) + 1);
	else
		return (write(fd, num, len));
}