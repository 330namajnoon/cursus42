/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:06:30 by simajnoo          #+#    #+#             */
/*   Updated: 2023/10/16 23:24:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

# define FT_NULL ((void *)0)

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 100
# endif

struct	s_data{
	char	buffer[BUFFER_SIZE];
	char	*rest;
	size_t	len;
};

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(char *s);

#endif