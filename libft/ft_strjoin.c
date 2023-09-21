#include "libft.h"
char *ft_strjoin(char const *s1, char const *s2)
{
    char    *res;
    unsigned int varl[3];

    varl[1] = ft_strlen((char*)s1);
    varl[2] = ft_strlen((char*)s2);
    res = (char*)malloc((varl[1] + varl[2] + 1) * sizeof(char));
    if (!res)
        return (FT_NULL);
    varl[0] = -1;
    while (++varl[0] < varl[1] + varl[2])
    {
        if(*s1 != 0)
        {      
            res[varl[0]] = *s1;
            s1++;
        }
        else if (*s2 != 0)
        {
            res[varl[0]] = *s2;
            s2++;
        }
    }
    res[varl[0]] = 0;
    return (res);
}