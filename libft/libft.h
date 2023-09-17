/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:13:39 by simajnoo          #+#    #+#             */
/*   Updated: 2023/09/11 23:08:34 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
size_t  ft_strlen(char *s);
void    *ft_memset(void *p, int c, size_t len);
void    ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dst, const void * src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
int ft_tolower(int c);
int ft_toupper(int c);

#endif
