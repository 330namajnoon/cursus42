#include "events.h"
#include "../fdf.h"

int key_down_hook(int keycode, t_scene_data *scene)
{
    const float rotation_speed = M_PI / 150;
    const float move_speed = 2;
    write(1, ft_itoa(keycode), ft_strlen(ft_itoa(keycode)));
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
