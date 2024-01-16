/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:19:29 by simajnoo          #+#    #+#             */
/*   Updated: 2024/01/14 20:28:12 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_type(char type, va_list args)
{
	int	i;

	i = 0;
	if (type == 's')
		i += putstrfd(va_arg(args, char*), 1);
	else if (type == 'p')
		i += putpointerfd(va_arg(args, void*), 1);
	else if (type == 'd' || type == 'i')
		i += putnbrfd(va_arg(args, int), 1);
	else if (type == 'c')
		i += putcharfd(va_arg(args, int), 1);
	else if (type == 'u')
		i += putunsigned_decimal_fd(va_arg(args, unsigned int), 1);
	else if (type == 'x')
		i += puthexfd(va_arg(args, unsigned int), "0123456789abcdef", 1);
	else if (type == 'X')
		i += puthexfd(va_arg(args, unsigned int), "0123456789ABCDEF", 1);
	return (i);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;

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
				i += get_type(*input, args);
			else if (*input == '%')
				i += putcharfd('%', 1);
		}
		else
			i += putcharfd(*input, 1);
		input++;
	}
	va_end(args);
	return (i);
}