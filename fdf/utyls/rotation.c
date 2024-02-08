#include "utyls.h"

t_eage *rotate_x(t_eage *eage, int angle)
{
	t_eage *rotated_eage;
	rotated_eage->start.x = eage->start.x;
	rotated_eage->end.x = eage->end.x;
	rotated_eage->start.y = eage->start.y * cos(angle) - eage->start.z * sin(angle);
	rotated_eage->end.y = eage->end.y * cos(angle) - eage->end.z * sin(angle);
	rotated_eage->start.z = eage->start.y * sin(angle) + eage->start.z * cos(angle);
	rotated_eage->end.z = eage->end.y * sin(angle) + eage->end.z * cos(angle);
	eage = rotated_eage;
	return (eage);
}

t_eage	*rotate_y(t_eage *eage, int angle)
{
	t_eage	*rotated_eage;
	rotated_eage->start.x = eage->start.x * cos(angle) + eage->start.z * sin(angle);
	rotated_eage->end.x = eage->end.x * cos(angle) + eage->end.z * sin(angle);
	rotated_eage->start.y = eage->start.y;
	rotated_eage->end.y = eage->end.y;
	rotated_eage->start.z = -eage->start.x * sin(angle) + eage->start.z * cos(angle);
	rotated_eage->end.z = -eage->end.x * sin(angle) + eage->end.z * cos(angle);
	eage = rotated_eage;
	return (eage);
}

t_eage	*rotate_z(t_eage	*eage, int angle)
{
	t_eage	*rotated_eage;
	rotated_eage->start.x = eage->start.x * cos(angle) - eage->start.y * sin(angle);
	rotated_eage->end.x = eage->end.x * cos(angle) - eage->end.y * sin(angle);
	rotated_eage->start.y = eage->start.x * sin(angle) + eage->start.y * cos(angle);
	rotated_eage->end.y = eage->end.x * sin(angle) + eage->end.y * cos(angle);
	rotated_eage->start.z = eage->start.z;
	rotated_eage->end.z = eage->end.z;
	eage = rotated_eage;
	return (eage);
}

t_eage *rotate_around_point(t_eage *eage, int axes, int angle,t_scene_data *scene)
{
	eage->start.x -= scene->center.x;
	eage->end.x -= scene->center.x;
	eage->start.y -= scene->center.y;
	eage->end.y -= scene->center.y;
	eage->start.z -= scene->center.z;
	eage->end.z -= scene->center.z;
	if (axes == 'X')
		eage = rotate_x(eage, angle);
	if (axes == 'Y')
		eage = rotate_y(eage, angle);
	if (axes == 'Z')
		eage = rotate_y(eage, angle);
	eage->start.x += scene->center.x;
	eage->end.x += scene->center.x;
	eage->start.y += scene->center.y;
	eage->end.y += scene->center.y;
	eage->start.z += scene->center.z;
	eage->end.z += scene->center.z;
	return (eage);
}

int rotate(int axes, int angle, t_scene_data *scene)
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
			eage = rotate_around_point(eage, axes, angle, scene);
			draw_line_3d(scene, c);
			c = c->next;
		}
		f = f->next;
	}
	return (1);
}