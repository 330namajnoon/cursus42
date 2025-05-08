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

#define M_PI 3.14159265358979323846

#define MOUSE_RIGHT 3
#define MOUSE_LEFT 1
#define MOUSE_S 2
#define MOUSE_S_T 4
#define MOUSE_S_B 5



typedef struct {
    float x;
    float y;
    float z;
} t_point3d;


typedef struct
{
    float x;
    float y;
    float z; 
} t_vector3;

typedef struct
{
    int x;
    int y;
    int z; 
} t_vector3_int;

typedef struct {
    t_vector3 start;
    t_vector3 end;
    int       color;
} t_eage;

typedef struct {
    void *mlx_ptr;
    void *win_ptr;
    t_eage  lines[12];
    t_point3d rotation_point;
    float rotation_x;
    float rotation_y;
    float rotation_z;
} t_env;

typedef struct 
{
    t_vector3   location;
    int         color;
} t_map_data;

typedef struct {
    int             is_active;
    t_vector3_int   pos;
}   t_mouse_status;

typedef struct {
    t_mouse_status b_l;
    t_mouse_status b_r;
    t_mouse_status b_s;
} t_mouse;

typedef struct
{
    t_list      *map_data;
    t_list      *eages;
    t_mouse     mouse;
    t_vector3   rotation;
    t_vector3   center;
    int         zoom;
    void        *mlx;
    void        *win;
} t_scene_data;



t_list	*read_map(char *src, t_list	*map_data);
t_scene_data	create_scene(t_vector3 center, t_vector3 initial_rotation, int width, int height, char *title);
t_list	*create_eages(t_list *map_data, t_list *eages);
int draw(t_scene_data *scene);
int get_color(char *hex_num);

#endif
