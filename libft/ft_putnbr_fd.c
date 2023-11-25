/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 00:44:38 by simajnoo          #+#    #+#             */
/*   Updated: 2023/09/26 00:51:58 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	special(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
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
		return (n * -1);
	}
	return (n);
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

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		len;
	char	num[11];

	i = 0;
	len = 0;
	if (special(n, fd))
		return ;
	n = check_negative(n, fd);
	len = num_len(n);
	i = len - 1;
	while (i >= 0)
	{
		num[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	i = -1;
	while (++i < len)
		write(fd, &num[i], 1);
}