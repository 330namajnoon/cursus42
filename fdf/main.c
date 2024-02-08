#include "fdf.h"

int main()
{
    t_scene_data scene;
    //t_list        *list;

    scene = create_scene((t_vector3){10, 0, 0},(t_vector3){0, 0, 0}, 800, 600, "New Scene");

    scene.map_data = read_map("./maps/test_maps/t1.fdf", scene.map_data);
    scene.eages = create_eages(scene.map_data, scene.eages);
    scene.zoom = 6;
    draw(&scene);

    return (0);
}