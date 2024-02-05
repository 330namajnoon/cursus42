#include "fdf.h"

int main()
{
    t_scene_data scene;
    //t_list        *list;

    scene = create_scene((t_vector3){0, 0, 0},(t_vector3){0, 0, 0}, 800, 600, "New Scene");

    scene.map_data = read_map("./maps/test_maps/10-2.fdf", scene.map_data);
    scene.eages = create_eages(scene.map_data, scene.eages);
    scene.zoom = 50;
    draw(&scene);
    while (scene.eages)
	{
		t_list *list = (t_list *)scene.eages->content;
		while (list)
		{
			t_eage *e = (t_eage *)list->content;
			/* code */
			printf("x: %f | y: %f | z: %f", e->start.x, e->start.y, e->start.z);
			list = list->next;
		}
			printf("\n");
		scene.eages = scene.eages->next;
	}
    // while (scene.map_data)
	// {
	// 	list = (t_list *)scene.map_data->content;
	// 	while (list)
	// 	{
	// 		/* code */
	// 		printf("%s", (char *)list->content);
	// 		list = list->next;
	// 	}
	// 	printf("\n");
	// 	scene.map_data = scene.map_data->next;
	// }
    return (0);
}