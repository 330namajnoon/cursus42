#include "fdf.h"

int hex_char_to_decimal(char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	else if (c >= 'A' && c <= 'F')
		return 10 + (c - 'A');
	else if (c >= 'a' && c <= 'f')
		return 10 + (c - 'a');
	return 0;
}

int get_color(char *hex_num)
{
	int	i;
	int length;
	int res;
	int base;

	res = 0;
	base = 1;
	
	if (ft_strlen(hex_num) - (hex_num[1] == 'x' || hex_num[1] == 'X'))
		length = ft_strlen(hex_num) - 2;
	else
		length = 0;
	i = length - 1;
	while (i >= 0)
	{
		if (hex_num[i] == 'x' || hex_num[i] == 'X')
			break;
		res += hex_char_to_decimal(hex_num[i]) * base;
		base *= 16;
		i--;
	}
	return (res);
}