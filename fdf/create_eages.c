
#include "fdf.h"



t_list	*create_eages(t_list *map_data, t_list *eages)
{
	t_list	*list;
	t_list	*list2;
	t_list	*map_data_c;
	t_eage	*eage;
	t_list	*eages_c;
	float	x;
	float	y;

	list = FT_NULL;
	list2 = FT_NULL;
	map_data_c = map_data;
	y = (float)0;
	while (map_data_c)
	{
		list = map_data_c->content;
		x = (float)0;
		eages_c = FT_NULL;
		while (list)
		{
			eage = (t_eage *)malloc(sizeof(t_eage));
			if (!eage)
				return (FT_NULL);
			eage->start.x = x;
			eage->start.y = y;
			eage->start.z = (float)ft_atoi((char *)list->content);
			if (list->next)
			{
				eage->end.x = x + 1;
				eage->end.y = y;
				eage->end.z = (float)ft_atoi((char *)list->next->content);
			}
			ft_lstadd_back(&eages_c, ft_lstnew(eage));
			list = list->next;
			x++;
		}
		ft_lstadd_back(&eages, ft_lstnew(eages_c));
		if (map_data_c->next)
		{
			list = map_data_c->content;
			list2 = map_data_c->next->content;
			x = (float)0;
			eages_c = FT_NULL;
			while (list && list2)
			{
				eage = (t_eage *)malloc(sizeof(t_eage));
				if (!eage)
					return (FT_NULL);
				eage->start.x = x;
				eage->start.y = y;
				eage->start.z = (float)ft_atoi((char *)list->content);
				if (list->next)
				{
					eage->end.x = x;
					eage->end.y = y + 1;
					eage->end.z = (float)ft_atoi((char *)list2->content);
				}
				ft_lstadd_back(&eages_c, ft_lstnew(eage));
				list = list->next;
				list2 = list2->next;
				x++;
			}
			ft_lstadd_back(&eages, ft_lstnew(eages_c));
		}
		(void)list2;
		map_data_c = map_data_c->next;
		y++;
	}
	return (eages);
}