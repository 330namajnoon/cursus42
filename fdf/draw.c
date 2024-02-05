#include "fdf.h"

t_env env;

t_vector3 rotate_x(t_vector3 p, float angle)
{
    t_vector3 rotated_p;
    rotated_p.x = p.x;
    rotated_p.y = p.y * cos(angle) - p.z * sin(angle);
    rotated_p.z = p.y * sin(angle) + p.z * cos(angle);
    return rotated_p;
}

t_vector3 rotate_y(t_vector3 p, float angle)
{
    t_vector3 rotated_p;
    rotated_p.x = p.x * cos(angle) + p.z * sin(angle);
    rotated_p.y = p.y;
    rotated_p.z = -p.x * sin(angle) + p.z * cos(angle);
    return rotated_p;
}

t_vector3 rotate_z(t_vector3 p, float angle)
{
    t_vector3 rotated_p;
    rotated_p.x = p.x * cos(angle) - p.y * sin(angle);
    rotated_p.y = p.x * sin(angle) + p.y * cos(angle);
    rotated_p.z = p.z;
    return rotated_p;
}

t_vector3 rotate_around_point(t_vector3 p, t_scene_data *scene)
{
    p.x -= scene->center.x;
    p.y -= scene->center.y;
    p.z -= scene->center.z;

    p = rotate_x(p, scene->rotation.x);
    p = rotate_y(p, scene->rotation.y);
    p = rotate_z(p, scene->rotation.z);

    p.x += scene->center.x;
    p.y += scene->center.y;
    p.z += scene->center.z;

    return p;
}

void draw_line_3d(t_scene_data *scene)
{
    t_list *f;
    t_list *c;
    t_eage *eage;

    f = scene->eages;
    while (f)
    {
        c = f->content;
        while (c->next)
        {
            eage = (t_eage *)c->content;
            //printf("(%d %d %d)[%d %d %d]", (int)eage->start.x, (int)eage->start.y, (int)eage->start.z, (int)eage->end.x, (int)eage->end.y, (int)eage->end.z);
            t_vector3 start_2d = {eage->start.x * scene->zoom, eage->start.y * scene->zoom, 0}; // Proyección simplificada
            t_vector3 end_2d = {eage->end.x * scene->zoom, eage->end.y * scene->zoom, 0};

            int dx = end_2d.x - start_2d.x;
            int dy = end_2d.y - start_2d.y;
            int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

            float x_inc = dx / (float)steps;
            float y_inc = dy / (float)steps;

            float x = start_2d.x;
            float y = start_2d.y;

            //printf("(%d %d)[%d %d]", (int)start_2d.x, (int)start_2d.x, (int)end_2d.x, (int)end_2d.y);
            for (int i = 0; i <= steps; i++)
            {
                mlx_pixel_put(scene->mlx, scene->win, x, y, 0xFFFFFF); // Dibuja en blanco
                x += x_inc;
                y += y_inc;
            }
            c = c->next;
        }
        // printf("\n");
        f = f->next;
    }
}

int key_hook(int keycode, t_scene_data *scene)
{
    t_list *f;
    t_list *c;
    t_eage *eage;
    const float rotation_speed = M_PI / 180;
    if (keycode == 120)
    {
        if (scene->rotation.x < 360)
            scene->rotation.x += rotation_speed;
        else
            scene->rotation.x = 0;
    }
    else if (keycode == 121)
    {
        if (scene->rotation.y < 360)
            scene->rotation.y += rotation_speed;
        else
            scene->rotation.y = 0;
    }
    else if (keycode == 122)
    {
        if (scene->rotation.z < 360)
            scene->rotation.z += rotation_speed;
        else
            scene->rotation.z = 0;
    }

    f = scene->eages;
    while (f)
    {
        c = f->content;
        while (c)
        {
            eage = (t_eage *)c->content;
            eage->start = rotate_around_point(eage->start, scene);
            eage->end = rotate_around_point(eage->end, scene);

            c = c->next;
        }

        f = f->next;
    }
    mlx_clear_window(scene->mlx, scene->win);
    draw_line_3d(scene);

    return 0;
}

int draw(t_scene_data *scene)
{
    mlx_key_hook(scene->win, key_hook, scene);
    draw_line_3d(scene);
    mlx_loop(scene->mlx);
    return (1);
}
