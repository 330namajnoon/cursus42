#include "../fdf.h"

void draw_line(t_scene_data *scene, t_list *c)
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