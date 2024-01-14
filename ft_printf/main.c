/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:13:56 by simajnoo          #+#    #+#             */
/*   Updated: 2024/01/14 20:12:54 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int argn, char *argv[])
{
	(void)argn;
	(void)argv;
	printf("\n%d", ft_printf("%s : %s %d ,\n", "hola", "mundo", "2024"));
	//printf("%s : %s %d ,", "hola", "mundo", "2024");
	return (0);
}