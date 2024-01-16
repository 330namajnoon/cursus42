
#include "ft_printf.h"

int putpointerfd(void *ptr, int fd)
{
    unsigned long address;
    char    base[16] = "0123456789abcdef";
    char buffer[16];
    int i;
    int digit;

    address = (unsigned long)ptr;
    i = 15;
    digit = 0;
    if (!ptr)
        return (write(fd, "(nil)", 5));
    while (address != 0 && i >= 0)
    {
        digit = address % 16;
        buffer[i--] = base[digit];
        address /= 16;
    }
    buffer[i--] = 'x';
    buffer[i] = '0';
    write(fd, &buffer[i], 16 - i);
    return (16 - i);
}