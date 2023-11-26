
#include "libft.h"

int	main(int argc, char *argv[])
{
	char **res;


	res = ft_split(argv[1], argv[2][0]);
	for (size_t i = 0; res[i]; i++)
	{
		printf("%s\n", res[i]);
	}
		
	return (0);
}