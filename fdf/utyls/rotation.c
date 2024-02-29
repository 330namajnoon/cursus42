#include "utyls.h"


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

t_vector3	rotate_around_point(t_vector3	p, int axes, int angle,t_scene_data *scene)
{
	p.x -= scene->center.x;
	p.y -= scene->center.y;
	p.z -= scene->center.z;
	if (axes == 'X')
		p = rotate_x(p, angle);
	if (axes == 'Y')
		p = rotate_x(p, angle);
	if (axes == 'Z')
		p = rotate_x(p, angle);
	p.x += scene->center.x;
	p.y += scene->center.y;
	p.z += scene->center.z;
	return (p);
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
			eage->start = rotate_around_point(eage->start,axes, angle, scene);
			eage->end = rotate_around_point(eage->end, axes, angle, scene);
			write(1, "(", 1);
			write(1, ft_itoa(eage->start.y), ft_strlen(ft_itoa(eage->start.y)));
			write(1, ")", 1);
			draw_line(scene, c);
			c = c->next;
		}
		f = f->next;
	}
	return (1);
}