/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:19:29 by simajnoo          #+#    #+#             */
/*   Updated: 2024/01/14 19:43:55 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	get_type(char type, void *arg)
{
	if (type == 's')
		putstr((char*)arg);
	else if (type == 'd')
		ft_putnbr_fd((int)arg, 1);
	else if (type == 'c')
		ft_putchar_fd((char)arg, 1);
	return (1);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	va_list	args;

	va_start(args, input);
	i = 0;
	while (1)
	{
		if (!*input)
			break ;
		if (*input == '%')
		{
			input++;
			if (ft_strchr("cspdiuxX", *input))
				i += get_type(*input, va_arg(args, void*));
			else if (*input == '%')
			{
				ft_putchar_fd('%', 1);
				i++;
			}
		}
		else
			write(1, &*input, 1);
		input++;
	}
	return (i);
}