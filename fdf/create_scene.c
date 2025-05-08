#include "fdf.h"

t_mouse	create_mouse()
{
	t_mouse mouse;

    mouse.b_l.is_active = 0;
    mouse.b_l.pos.x = 0;
    mouse.b_l.pos.y = 0;
    mouse.b_l.pos.z = 0;

    mouse.b_r.is_active = 0;
    mouse.b_r.pos.x = 0;
    mouse.b_r.pos.y = 0;
    mouse.b_r.pos.z = 0;

    mouse.b_s.is_active = 0;
    mouse.b_s.pos.x = 0;
    mouse.b_s.pos.y = 0;
    mouse.b_s.pos.z = 0;


    return (mouse);
}


t_scene_data	create_scene(t_vector3 center, t_vector3 initial_rotation, int width, int height, char *title)
{
	t_scene_data	scene;

	scene.mlx = mlx_init();
	scene.win = mlx_new_window(scene.mlx, width, height, title);
	scene.center = center;
	scene.eages = FT_NULL;
	scene.map_data = FT_NULL;
	scene.rotation = initial_rotation;
	scene.mouse = create_mouse();
	scene.zoom = 1;
	return (scene);
}