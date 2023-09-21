#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char             *res;
    unsigned int     i;

    res = (char *)malloc((len + 1) * sizeof(char));
    if (!res)
        return (FT_NULL);
    i = -1;
    while (++i < len && s[start] != 0) {
        res[i] = s[start];
        start++;
    }
    res[i] = 0;
    return (res);
}