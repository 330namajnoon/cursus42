
#include "ft_printf.h"

int putunsigned_decimal_fd(unsigned int number, int fd)
{
    char    buffer[20];
    int     i;
    int     digit;

    i = 19;
    if (number == 0)
        return (write(fd, "0", 1));
    else
    {
        while (number != 0 && i >= 0)
        {
            digit = number % 10;
            buffer[i--] = '0' + digit;
            number /= 10;
        }
        write(fd, &buffer[i+1], 19 - i);
    }
    return (19 - i);
}
