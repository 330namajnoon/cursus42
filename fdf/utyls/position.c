#include "../fdf.h"

t_eage	*muve_x(t_eage	*eage, int force)
{
    t_eage	*moved_eage;
    moved_eage->start.x = eage->start.x + force;
    moved_eage->end.x = eage->end.x + force;
    moved_eage->start.y = eage->start.y;
    moved_eage->end.y = eage->end.y;
    moved_eage->start.z = eage->start.z;
    moved_eage->end.z = eage->end.z;
	eage = moved_eage;
    return (eage);
}

t_eage	*muve_y(t_eage	*eage, int force)
{
    t_eage	*moved_eage;
    moved_eage->start.x = eage->start.x;
    moved_eage->end.x = eage->end.x;
    moved_eage->start.y = eage->start.y + force;
    moved_eage->end.y = eage->end.y + force;
    moved_eage->start.z = eage->start.z;
    moved_eage->end.z = eage->end.z;
	eage = moved_eage;
    return (eage);
}

t_eage	*muve_z(t_eage	*eage, int force)
{
    t_eage	*moved_eage;
    moved_eage->start.x = eage->start.x;
    moved_eage->end.x = eage->end.x;
    moved_eage->start.y = eage->start.y;
    moved_eage->end.y = eage->end.y;
    moved_eage->start.z = eage->start.z + force;
    moved_eage->end.z = eage->end.z + force;
	eage = moved_eage;
    return (eage);
}

t_eage	*move_around_point(t_eage	*eage, int axes, int force)
{
    if (axes == 'X')
        eage = muve_x(eage, force);
    if (axes == 'Y')
        eage = muve_y(eage, force);
    if (axes == 'Z')
        eage = muve_z(eage, force);
    return (eage);
}

int move(int axes, int force, t_scene_data *scene)
{
	t_list *f;
	t_list *c;
	t_eage *eage;
	f = scene->eages;
	mlx_clear_window(scene->mlx, scene->win);
	while (f)
	{
		c = f->content;
		while (c->next)
		{
			eage = (t_eage *)c->content;
			eage = move_around_point(eage, axes, force);
			draw_line_3d(scene, c);
			c = c->next;
		}
		f = f->next;
	}
	return (1);
}