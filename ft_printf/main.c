/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:13:56 by simajnoo          #+#    #+#             */
/*   Updated: 2024/01/18 21:59:49 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	main(int argn, char *argv[])
{
	(void)argn;
	(void)argv;
	//printf("\n%d", ft_printf("%s : %s %d - %c | %p | ,\n", "hola", "mundo", 2024, 'c', "hola"));
	//void *str = "Sina";
	// ft_printf("%c | %s | %p | %d | %i | %u | %x | %X\n", 'a', "Hola Mundo", str, 2024, 42, -110, 2025, 2025);
	// printf("%c | %s | %p | %d | %i | %u | %x | %X\n", 'a', "Hola Mundo", str, 2024, 42, -110, 2025, 2025);
	//char *p = ft_strdup("Hola mundo");
	ft_printf("%d\n", ft_printf("| %p |", (void *)-14523));
	printf("%d\n", printf("| %p |", (void *)-14523));
	//printf("%d\n", printf("NULL %s NULL\n", NULL));

	return (0);
}