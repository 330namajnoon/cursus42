
#include "ft_printf.h"

int putunsigned_decimal_fd(unsigned long number, int fd)
{
    char    buffer[20];
    int i;
    int digit;
    char base[10] = "0123456789";

    i = 19;
    buffer[i--] = 0;
    if (number == 0)
    {
        buffer[i--] = '0';
    }
    else
    {
        while (number != 0 && i >= 0)
        {
            digit = number % 10;
            buffer[i--] = base[digit];
            number /= 10;
        }
        write(fd, &buffer[i], 20 - i);
    }
    return (20 - i);
}