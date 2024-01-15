
#include "ft_printf.h"


int puthexfd(unsigned long number, char *base, int fd)
{
    int i;
    char    buffer[16];
    int     digit;

    i = 15;
    digit = 0;
    buffer[i--] = 0;
    if (number == 0)
    {
        buffer[i--] = '0';
    }
    else
    {
        while (number != 0 && i >= 0)
        {
            digit = number % 16;
            buffer[i--] = base[digit];
            number /= 16;
        }
        write(fd, &buffer[i], 15 - i);
    }
    return (15 - i);
}