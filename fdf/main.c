#include "fdf.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

void	put_pixel(t_img *img, int x, int y, int color)
{
	int	i;

	i = 0;
	while (img->addr[i])
	{
		printf("%c", img->addr[i]);
		img->addr[i] = color;
		i++;
	}
	
}

int	main(void)
{
	void	*mlx;
	void	*win;
	t_img	img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "fdf");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	printf("Addr: %p, BPP: %d, Line length: %d, Endian: %d\n", img.addr, img.bits_per_pixel, img.line_length, img.endian);
	if (!img.addr)
	{
		printf("Error: mlx_get_data_addr() falló.\n");
		return (1);
	}
	// Dibujar una línea de píxeles rojos en la imagen
	for (int i = 250; i < 272; i++)
		put_pixel(&img, i, 250, 0xFFFFFF);

	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}