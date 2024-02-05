#include "fdf.h"

t_scene_data	create_scene(t_vector3 center, t_vector3 initial_rotation, int width, int height, char *title)
{
	t_scene_data	scene;

	scene.mlx = mlx_init();
	scene.win = mlx_new_window(scene.mlx, width, height, title);
	scene.center = center;
	scene.eages = FT_NULL;
	scene.map_data = FT_NULL;
	scene.rotation = initial_rotation;
	scene.zoom = 1;
	return (scene);
}