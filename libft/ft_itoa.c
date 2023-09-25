/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:52:42 by simajnoo          #+#    #+#             */
/*   Updated: 2023/09/25 23:56:18 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	set_sign(int n)
{
	if (n >= 0)
		return (1);
	else
		return (-1);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		vars[3];
	long	n1;

	vars[2] = set_sign(n);
	n1 = n;
	vars[1] = num_len(n1 * vars[2]);
	if (n < 0)
		vars[1]++;
	vars[0] = -1;
	res = (char *)malloc((vars[1] + 1) * sizeof(char));
	if (!res)
		return (FT_NULL);
	res[vars[1]] = 0;
	vars[1]--;
	n1 *= vars[2];
	while ((vars[1] >= 0 && n1 != 0) || (vars[1] >= 0 && n == 0))
	{
		res[vars[1]] = (n1 % 10) + '0';
		n1 /= 10;
		vars[1]--;
	}
	if (vars[2] < 0)
		res[vars[1]] = '-';
	return (res);
}
