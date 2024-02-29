#include "fdf.h"

// void put_pixel_to_image(char *img, int x, int y, int color, int size_line, int bpp)
// {
//     if (x < 0 || y < 0)
//         return;
//     int pixel = (x * (bpp / 8)) + (y * size_line);

//     img[pixel] = color & 0xFF;             // Azul
//     img[pixel + 1] = (color >> 8) & 0xFF;  // Verde
//     img[pixel + 2] = (color >> 16) & 0xFF; // Rojo
//     // Asume que bpp es 32; no se modifica el cuarto byte, que sería el alfa
// }

// void draw_lin_3d(char *img_data, int size_line, int bpp, t_eage *eage)
// {
//     // Asume que ya tienes una imagen creada y su dirección obtenida

//     // Proyección simplificada, puedes ajustar esto según tu sistema de coordenadas
//     t_point3d start_2d = {eage->start.x, eage->start.y, 0};
//     t_point3d end_2d = {eage->end.x, eage->end.y, 0};

//     // Algoritmo de línea (Bresenham, DDA, etc.)
//     // Aquí usamos una versión simplificada para ilustrar
//     int dx = fabsf(end_2d.x - start_2d.x), sx = start_2d.x < end_2d.x ? 1 : -1;
//     int dy = -fabsf(end_2d.y - start_2d.y), sy = start_2d.y < end_2d.y ? 1 : -1;
//     int err = dx + dy, e2;

//     while (1)
//     {
//         put_pixel_to_image(img_data, start_2d.x, start_2d.y, eage->color, size_line, bpp);
//         if (start_2d.x == end_2d.x && start_2d.y == end_2d.y)
//             break;
//         e2 = 2 * err;
//         if (e2 >= dy)
//         {
//             err += dy;
//             start_2d.x += sx;
//         }
//         if (e2 <= dx)
//         {
//             err += dx;
//             start_2d.y += sy;
//         }
//     }
// }

// int main()
// {
//     t_list *f;
//     t_list *c;
//     t_eage *eage;

//     t_scene_data scene;
//     void *img_ptr;
//     char *img_data;
//     int bits_per_pixel;
//     int size_line;
//     int endian;
//     // t_list        *list;
//     scene = create_scene((t_vector3){10, 0, 0}, (t_vector3){0, 0, 0}, 800, 600, "New Scene");

//     scene.map_data = read_map("./maps/test_maps/50-4.fdf", scene.map_data);
//     scene.eages = create_eages(scene.map_data, scene.eages);
//     scene.zoom = 6;
//     // draw(&scene);
//     img_ptr = mlx_new_image(scene.mlx, 1000, 1000);
//     img_data = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);
//     f = scene.eages;
//     while (f)
//     {
//         c = f->content;
//         while (c->next)
//         {
//             eage = (t_eage *)c->content;
//             draw_lin_3d(img_data, size_line, bits_per_pixel, eage);
//             c = c->next;
//         }
//         f = f->next;
//     }
//     mlx_put_image_to_window(scene.mlx, scene.win, img_ptr, 0, 0);
//     mlx_loop(scene.mlx);
//     mlx_destroy_image(scene.mlx, img_ptr);
//     return (0);
// }

void draw_line_(void *img, int x0, int y0, int x1, int y1, int color)
{
    char *data;
    int bits_per_pixel;
    int size_line;
    int endian;
    int dx;
    int dy;
    int stepX;
    int stepY;
    int fraction;

    data = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
    dx = x1 - x0;
    dy = y1 - y0;
    stepX = (dx > 0) ? 1 : -1;
    stepY = (dy > 0) ? 1 : -1;
    dx = abs(dx);
    dy = abs(dy);

    if (dx > dy)
    {
        fraction = dy * 2 - dx;
        while (x0 != x1)
        {
            if (fraction >= 0)
            {
                y0 += stepY;
                fraction -= dx * 2;
            }
            x0 += stepX;
            fraction += dy * 2;
            *(int *)(data + (x0 + y0 * size_line / 8) * 8) = color;
        }
    }
    else
    {
        fraction = dx * 2 - dy;
        while (y0 != y1)
        {
            if (fraction >= 0)
            {
                x0 += stepX;
                fraction -= dy * 2;
            }
            y0 += stepY;
            fraction += dx * 2;
            *(int *)(data + (x0 + y0 * size_line / 8) * 8) = color;
        }
    }
}

int main()
{
    t_list *f;
    t_list *c;
    t_eage *eage;
    t_scene_data scene;
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    int img_width = 800;
    int img_height = 600;

    scene = create_scene((t_vector3){10, 0, 0}, (t_vector3){0, 0, 0}, 800, 600, "New Scene");

    scene.map_data = read_map("./maps/test_maps/50-4.fdf", scene.map_data);
    scene.eages = create_eages(scene.map_data, scene.eages);
    scene.zoom = 6;
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Ventana de ejemplo");
    img_ptr = mlx_new_image(mlx_ptr, img_width, img_height);

    // Dibujar la línea blanca en la imagen
    f = scene.eages;
    while (f)
    {
        c = f->content;
        while (c->next)
        {
            eage = (t_eage *)c->content;
            draw_line_(img_ptr, eage->start.x, eage->start.y, eage->end.x, eage->end.y, eage->color);
            c = c->next;
        }
        f = f->next;
    }

    // Mostrar la imagen en la ventana
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
    mlx_loop(mlx_ptr);

    return (0);
}