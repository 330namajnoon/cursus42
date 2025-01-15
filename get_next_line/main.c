/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 21:06:39 by simajnoo          #+#    #+#             */
/*   Updated: 2025/01/13 16:35:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argn, char *argv[])
{
	int		file;
	char	*res;

	file = open(argv[1], 0);
	if (file == -1)
		return (0);
	for (size_t i = 0; i < (unsigned int)atoi(argv[2]); i++)
	{
		res = get_next_line(file);
		if (!res)
			break;
		printf("%s", res);
		free(res);
	}
	close(file);
	(void)argn;
	return (0);
}

// void manejarStringEstatico(const char *nuevoTexto) {
//     static char *stringEstatico = NULL;

//     // Liberar memoria anterior si existe (opcional, en caso de reutilización)
//     if (stringEstatico != NULL) {
//         free(stringEstatico);
//     }

//     // Asignar memoria suficiente para el nuevo texto
//     stringEstatico = (char *)malloc(strlen(nuevoTexto) + 1);
//     if (stringEstatico == NULL) {
//         perror("Error al asignar memoria");
//         exit(1);
//     }

//     // Copiar el nuevo texto en el string estático
//     strcpy(stringEstatico, nuevoTexto);

//     // Imprimir el contenido actual del string
//     printf("String actual: %s\n", stringEstatico);
// }

// int main() {
//     manejarStringEstatico("Hola");
//     manejarStringEstatico("Mundo dinámico");
//     manejarStringEstatico("¡Más datos!");
//     return 0;
// }