/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:13:39 by simajnoo          #+#    #+#             */
/*   Updated: 2023/11/26 18:24:50 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include <X11/X.h>
#include "utyls/utyls.h"
#include "events/events.h"
#include "utyls/structs.h"
#include "utyls/structs.h"

#define M_PI 3.14159265358979323846

#define MOUSE_RIGHT 3
#define MOUSE_LEFT 1
#define MOUSE_S 2
#define MOUSE_S_T 4
#define MOUSE_S_B 5


t_list	*read_map(char *src, t_list	*map_data);
t_scene_data	create_scene(t_vector3 center, t_vector3 initial_rotation, int width, int height, char *title);
t_list	*create_eages(t_list *map_data, t_list *eages);
int draw(t_scene_data *scene);
int get_color(char *hex_num);

#endif
