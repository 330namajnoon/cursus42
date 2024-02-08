#include "events.h"

int key_hook(int keycode, t_scene_data *scene)
{
    t_list *f;
    t_list *c;
    t_eage *eage;
    const float rotation_speed = M_PI / 150;
    const float muve_speed = 2;
    mlx_clear_window(scene->mlx, scene->win);
    if (keycode == 120)
    {
        if (scene->rotation.x < 360)
        {
            scene->rotation.x = rotation_speed;
            f = scene->eages;
            while (f)
            {
                c = f->content;
                while (c->next)
                {
                    eage = (t_eage *)c->content;
                    eage->start = rotate_around_point(eage->start, scene, 'X');
                    eage->end = rotate_around_point(eage->end, scene, 'X');
                    draw_line_3d(scene, c);
                    c = c->next;
                }
                f = f->next;
            }
        }
    }
    else if (keycode == 121)
    {
        if (scene->rotation.y < 360)
        {
            scene->rotation.y = rotation_speed;
            f = scene->eages;
            while (f)
            {
                c = f->content;
                while (c->next)
                {
                    eage = (t_eage *)c->content;
                    eage->start = rotate_around_point(eage->start, scene, 'Y');
                    eage->end = rotate_around_point(eage->end, scene, 'Y');
                    draw_line_3d(scene, c);
                    c = c->next;
                }
                f = f->next;
            }
        }
    }
    else if (keycode == 122)
    {
        if (scene->rotation.z < 360)
        {
            scene->rotation.z = rotation_speed;
            f = scene->eages;
            while (f)
            {
                c = f->content;
                while (c->next)
                {
                    eage = (t_eage *)c->content;
                    eage->start = rotate_around_point(eage->start, scene, 'Z');
                    eage->end = rotate_around_point(eage->end, scene, 'Z');
                    draw_line_3d(scene, c);
                    c = c->next;
                }
                f = f->next;
            }
        }
    }
    else if (keycode == 65363)
    {

        f = scene->eages;
        while (f)
        {
            c = f->content;
            while (c->next)
            {
                eage = (t_eage *)c->content;
                eage->start = muve_around_point(eage->start, 'X', muve_speed);
                eage->end = muve_around_point(eage->end, 'X', muve_speed);
                c = c->next;
            }
            f = f->next;
        }
        scene->center.x += muve_speed;
    }
    else if (keycode == 65361)
    {
        f = scene->eages;
        while (f)
        {
            c = f->content;
            while (c->next)
            {
                eage = (t_eage *)c->content;
                eage->start = muve_around_point(eage->start, 'X', -muve_speed);
                eage->end = muve_around_point(eage->end, 'X', -muve_speed);
                c = c->next;
            }
            f = f->next;
        }
        scene->center.x -= muve_speed;
    }
    else if (keycode == 65364)
    {
        f = scene->eages;
        while (f)
        {
            c = f->content;
            while (c->next)
            {
                eage = (t_eage *)c->content;
                eage->start = muve_around_point(eage->start, 'Y', muve_speed);
                eage->end = muve_around_point(eage->end, 'Y', muve_speed);
                c = c->next;
            }
            f = f->next;
        }
        scene->center.y += muve_speed;
    }
    else if (keycode == 65362)
    {
        f = scene->eages;
        while (f)
        {
            c = f->content;
            while (c->next)
            {
                eage = (t_eage *)c->content;
                eage->start = muve_around_point(eage->start, 'Y', -muve_speed);
                eage->end = muve_around_point(eage->end, 'Y', -muve_speed);
                c = c->next;
            }
            f = f->next;
        }
        scene->center.x -= muve_speed;
    }

    //mlx_clear_window(scene->mlx, scene->win);
    //draw_lines_3d(scene);

    // write(1, ft_itoa(keycode), ft_strlen(ft_itoa(keycode)));
    return 0;
}
