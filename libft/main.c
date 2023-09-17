#include "libft.h"

int main(int argn, char *argv[])
{
	char p[20] = "sina";
	char p1[] = "majnoon";
	

	size_t len = ft_strlcat(p,p1,7);
	
	printf("%s\n",p);
	printf("%zu\n",len);


	
	(void)argn;
	(void)argv;
	return 0;
}
