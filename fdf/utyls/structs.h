#ifndef STRUCTS_H
# define STRUCTS_H

#include "../fdf.h"

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

#endif