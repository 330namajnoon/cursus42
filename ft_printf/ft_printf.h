/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:13:41 by simajnoo          #+#    #+#             */
/*   Updated: 2024/01/14 20:27:19 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

int		putstrfd(char *str, int fd);
int		putnbrfd(int nbr, int fd);
int     putcharfd(int c, int fd);
int     putpointerfd(void *ptr, int fd);
int     putunsigned_decimal_fd(unsigned int number, int fd);
int     puthexfd(unsigned int number,char *base, int fd);
int		ft_printf(const char *input, ...);

#endif
