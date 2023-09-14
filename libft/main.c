#include "libft.h"

int main(int argn, char *argv[])
{
	(void)argn;
	printf("%d is assci\n ",ft_isascii(argv[1][0]));
	printf("%d is printable\n ",ft_isprint(argv[1][0]));
	printf("%zustrlen\n ",ft_strlen(argv[1]));
	return 0;
}
