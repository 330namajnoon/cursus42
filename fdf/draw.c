#include "fdf.h"

t_env env;



void draw_line_3d(t_scene_data *scene, t_list *c)
{
    t_eage *eage;
    t_eage *eage1;

    eage = (t_eage *)c->content;
    eage1 = (t_eage *)c->next->content;
    // printf("(%d %d %d)[%d %d %d]", (int)eage->start.x, (int)eage->start.y, (int)eage->start.z, (int)eage->end.x, (int)eage->end.y, (int)eage->end.z);
    t_vector3 start_2d = {eage->start.x * scene->zoom, eage->start.y * scene->zoom, 0}; // Proyección simplificada
    t_vector3 end_2d = {eage->end.x * scene->zoom, eage->end.y * scene->zoom, 0};

    int dx = end_2d.x - start_2d.x;
    int dy = end_2d.y - start_2d.y;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float x_inc = dx / (float)steps;
    float y_inc = dy / (float)steps;

    float x = start_2d.x;
    float y = start_2d.y;

    // printf("(%d %d)[%d %d]", (int)start_2d.x, (int)start_2d.x, (int)end_2d.x, (int)end_2d.y);
    for (int i = 0; i <= steps; i++)
    {
        if (eage->color == 0)
            eage->color = 0xFFFFFF;
        if (eage1->color == 0)
            eage1->color = 0xFFFFFF;
        if (i <= steps / 2)
            mlx_pixel_put(scene->mlx, scene->win, x, y, eage->color); // Dibuja en blanco
        else
            mlx_pixel_put(scene->mlx, scene->win, x, y, eage1->color); // Dibuja en blanco

        x += x_inc;
        y += y_inc;
    }
}

void draw_lines_3d(t_scene_data *scene)
{
    t_list *f;
    t_list *c;
    t_eage *eage;
    t_eage *eage1;

    f = scene->eages;
    while (f)
    {
        c = f->content;
        while (c->next)
        {
            eage = (t_eage *)c->content;
            eage1 = (t_eage *)c->next->content;
            // printf("(%d %d %d)[%d %d %d]", (int)eage->start.x, (int)eage->start.y, (int)eage->start.z, (int)eage->end.x, (int)eage->end.y, (int)eage->end.z);
            t_vector3 start_2d = {eage->start.x * scene->zoom, eage->start.y * scene->zoom, 0}; // Proyección simplificada
            t_vector3 end_2d = {eage->end.x * scene->zoom, eage->end.y * scene->zoom, 0};

            int dx = end_2d.x - start_2d.x;
            int dy = end_2d.y - start_2d.y;
            int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

            float x_inc = dx / (float)steps;
            float y_inc = dy / (float)steps;

            float x = start_2d.x;
            float y = start_2d.y;

            // printf("(%d %d)[%d %d]", (int)start_2d.x, (int)start_2d.x, (int)end_2d.x, (int)end_2d.y);
            for (int i = 0; i <= steps; i++)
            {
                if (eage->color == 0)
                    eage->color = 0xFFFFFF;
                if (eage1->color == 0)
                    eage1->color = 0xFFFFFF;
                if (i <= steps / 2)
                    mlx_pixel_put(scene->mlx, scene->win, x, y, eage->color); // Dibuja en blanco
                else
                    mlx_pixel_put(scene->mlx, scene->win, x, y, eage1->color); // Dibuja en blanco

                x += x_inc;
                y += y_inc;
            }
            c = c->next;
        }
        // printf("\n");
        f = f->next;
    }
}

int button_press_hook(int button, int x, int y, t_scene_data *scene)
{
    const int zoom_speed = 1;
    if (button == MOUSE_S_T)
    {
        scene->zoom += zoom_speed;
        draw_lines_3d(scene);
    }
    else if (button == MOUSE_S_B)
    {
        scene->zoom -= zoom_speed;
        if (scene->zoom < 1)
            scene->zoom = 1;
        draw_lines_3d(scene);
    }
    else if (button == MOUSE_LEFT)
    {
        scene->mouse.b_l.is_active = 1;
        scene->zoom -= zoom_speed;
        if (scene->zoom < 1)
            scene->zoom = 1;
        draw_lines_3d(scene);
    }
    mlx_clear_window(scene->mlx, scene->win);
    draw_lines_3d(scene);
    (void)x;
    (void)y;
    write(1, ft_itoa(button), ft_strlen(ft_itoa(button)));
    return 0;
}
int button_release_hook(int button, int x, int y, t_scene_data *scene)
{
    const int zoom_speed = 1;
    if (button == MOUSE_S_T)
    {
        scene->zoom += zoom_speed;
        draw_lines_3d(scene);
    }
    else if (button == MOUSE_S_B)
    {
        scene->zoom -= zoom_speed;
        if (scene->zoom < 1)
            scene->zoom = 1;
        draw_lines_3d(scene);
    }
    else if (button == MOUSE_LEFT)
    {
        scene->mouse.b_l.is_active = 0;
        scene->mouse.b_l.pos.x = x;
        scene->mouse.b_l.pos.y = y;
        scene->zoom -= zoom_speed;
    }
    mlx_clear_window(scene->mlx, scene->win);
    draw_lines_3d(scene);
    write(1, ft_itoa(button), ft_strlen(ft_itoa(button)));
    return 0;
}

int mouse_move_hook(int x, int y, t_scene_data *scene)
{
    const float rotation_speed = M_PI / 150;
    if (scene->mouse.b_l.is_active)
    {
        if (x > scene->mouse.b_l.pos.x)
            rotate(x, rotation_speed, scene);
        write(1, ft_itoa(x), ft_strlen(ft_itoa(x)));
    }
    (void)x;
    (void)y;
    (void)scene;

    return 0;
}


int draw(t_scene_data *scene)
{
    t_list *f;
    t_list *c;
    int x_ofset;
    int y_ofset;

    x_ofset = 0;
    y_ofset = 0;
    f = scene->map_data;
    while (f)
    {
        c = f->content;
        x_ofset = 0;
        while (c->next)
        {
            x_ofset++;
            c = c->next;
        }
        y_ofset++;
        f = f->next;
    }
    scene->center.x = x_ofset / 2;
    scene->center.y = y_ofset / 2;

    mlx_hook(scene->win, KeyPress, KeyPressMask, key_down_hook, scene);
    mlx_hook(scene->win, ButtonPress, ButtonPressMask, button_press_hook, scene);
    mlx_hook(scene->win, ButtonRelease, ButtonReleaseMask, button_release_hook, scene);
    mlx_hook(scene->win, 6, PointerMotionMask, mouse_move_hook, scene);
    // mlx_loop_hook(scene->mlx, mouse_muve_hook, scene);
    draw_lines_3d(scene);
    mlx_loop(scene->mlx);
    return (1);
}
