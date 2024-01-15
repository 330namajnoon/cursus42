
#include "ft_printf.h"

int putcharfd(int c, int fd)
{
    write(fd, &c, 1);
    return (1);
}