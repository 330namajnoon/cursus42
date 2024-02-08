#include "events.h"

int key_down_hook(int keycode, t_scene_data *scene)
{
    t_list *f;
    t_list *c;
    t_eage *eage;
    const float rotation_speed = M_PI / 150;
    const float move_speed = 2;
    mlx_clear_window(scene->mlx, scene->win);
    if (keycode == 120)
		rotate('X', rotation_speed, scene);
    else if (keycode == 121)
		rotate('Y', rotation_speed, scene);
    else if (keycode == 122)
		rotate('Z', rotation_speed, scene);
    else if (keycode == 65363)
       move('X', move_speed, scene);
    else if (keycode == 65361)
       move('X', -move_speed, scene);
    else if (keycode == 65364)
       move('Y', move_speed, scene);
    else if (keycode == 65362)
       move('Y', -move_speed, scene);
    return 0;
}
