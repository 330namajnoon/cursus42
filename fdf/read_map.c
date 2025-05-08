
#include "fdf.h"




t_list	*read_map(char *src, t_list	*map_data)
{
	char			*line;
	char			**split;
	int				fd;
	int				i;
	t_list			*list;

	list = FT_NULL;
	fd = open(src, 0);
	i = -1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		split = ft_split(line, ' ');
		i = -1;
		list = FT_NULL;
		while (split[++i])
			ft_lstadd_back(&list, ft_lstnew(split[i]));
		ft_lstadd_back(&map_data, ft_lstnew(list));
	}
	close(fd);
	return (map_data);
}