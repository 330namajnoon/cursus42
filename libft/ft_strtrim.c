#include "libft.h"
char *ft_strtrim(char const *s1, char const *set)
{
    char    *res;
    int     vars[3];

    while (*s1 != 0)
    {
        vars[0] = -1;
        vars[1] = 0;
        while (set[++vars[0]] != 0)
            if (set[vars[0]] == *s1 && vars[1] != 0)
                vars[1] = 1;
        if (vars[1] == 1)
            s1++;
        else
        {
            return ((char*)s1);
            // res = (char*)malloc(ft_strlen((char*)s1 + 1 * sizeof(char)));
            // if (!res)
            //     return (FT_NULL);
            // vars[2] = -1;
            // while (s1[++vars[2]] != 0)
            //     res[vars[2]] = s1[vars[2]];
            // return (res);
        }
    }
    res = (char*)ft_calloc(1, sizeof(char));
    return (res);
}