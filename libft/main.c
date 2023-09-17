#include "libft.h"

int main(int argn, char *argv[])
{
	char *p = "+10sina";
	char *p1;
	

	p1 = ft_strdup(p);
	if(p1)
	{
		printf("%s",p1);
		for (size_t i = 0; i < ft_strlen(p); i++)
		{
			
		}
		free(p1);
	}
	
	//printf("%s",res);

	(void)argn;
	(void)argv;
	return 0;
}
