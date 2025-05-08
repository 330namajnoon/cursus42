
#include "fdf.h"

int get_eage_color(char *str)
{
	char	**split;

	split = ft_split(str, ','); 
	if (split[1])
	{
		return (get_color(split[1]));
	}
	else
	{
		return (0xffffff);
	}
}

float	get_eage_z(char *str)
{
	char	**split;

	split = ft_split(str, ','); 
	return ((float)ft_atoi(split[0]));
}

t_list *create_eages_xx(t_list *map_data, float y)
{
	t_list *list;
	t_list *eages;
	t_eage *eage;
	float x;

	list = map_data->content;
	eages = FT_NULL;
	x = (float)0;
	while (list)
	{
		eage = (t_eage *)malloc(sizeof(t_eage));
		if (!eage)
			return (FT_NULL);
		eage->start.x = x;
		eage->start.y = y;
		eage->color = get_eage_color((char *)list->content);
		eage->start.z = get_eage_z((char *)list->content);
		if (list->next)
		{
			eage->end.x = x + 1;
			eage->end.y = y;
			eage->end.z = get_eage_z((char *)list->next->content);
		}
		ft_lstadd_back(&eages, ft_lstnew(eage));
		list = list->next;
		x++;
	}
	return (eages);
}

t_list *create_eages_xy(t_list *map_data, float y)
{
	t_list *list;
	t_list *list2;
	t_list *eages;
	t_eage *eage;
	float x;

	list = map_data->content;
	list2 = map_data->next->content;
	eages = FT_NULL;
	x = (float)0;
	while (list && list2)
	{
		eage = (t_eage *)malloc(sizeof(t_eage));
		if (!eage)
			return (FT_NULL);
		eage->start.x = x;
		eage->start.y = y;
		eage->color = get_color((char *)list->content);
		eage->start.z = get_eage_z((char *)list->content);
		if (list->next)
		{
			eage->end.x = x;
			eage->end.y = y + 1;
			eage->end.z = get_eage_z((char *)list2->content);
		}
		ft_lstadd_back(&eages, ft_lstnew(eage));
		list = list->next;
		list2 = list2->next;
		x++;
	}
	return (eages);
}

t_list *create_eages(t_list *map_data, t_list *eages)
{
	t_list *map_data_c;
	float y;
	map_data_c = map_data;
	y = (float)0;
	while (map_data_c)
	{
		ft_lstadd_back(&eages, ft_lstnew(create_eages_xx((t_list *)map_data_c, y)));
		if (map_data_c->next)
		{
			ft_lstadd_back(&eages, ft_lstnew(create_eages_xy((t_list *)map_data_c, y)));
		}
		map_data_c = map_data_c->next;
		y++;
	}
	return (eages);
}