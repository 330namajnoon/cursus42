#include <mlx.h>
#include <stdlib.h>

int main()
{
    void    *mlx;
    void    *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "Mi primera ventana de MinilibX");

    return (0);
}