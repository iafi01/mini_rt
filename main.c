#include <mlx.h>
#include "includes/obj.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}
int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}
int             main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    int width = 1500;
    int height = 1200;
    int x;
    int y;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, width, height, "IAFI");
    img.img = mlx_new_image(mlx, width, height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);



    for (int j = width-1; j >= 0; --j)
	{
		for (int i = 0; i < height; ++i)
		{
			float r = (float)(j) / (float)(width-50);
            float g = (float)(j) / (float)(width-50);             
            float b = (float)(j) / (float)(width-50);

            int ir = (int)(255 * r);
            int ig = (int)(255 * g);
			int ib = (int)(255 * b);
			int color = create_trgb(0, ir, ig, ib);
			my_mlx_pixel_put(&img, j, i, color);
        }
    }
    //rettangolo finestra che emette luce
    x = width-50;
    while (x != width)
    {
        y = 0;
        while (y < height)
        {
            my_mlx_pixel_put(&img, x, y, 0x00449988);
            y++;
        }
        x++;
    }
    //cerchio
    int max = 200;
     x = 100;
    while (x != max)
    {
        y = 100;
        while (y < max)
        {
            my_mlx_pixel_put(&img, x, y, 0x00449988);
            if (x == max-50 || y == max-50)
                my_mlx_pixel_put(&img, x, y, 0x00665544);
            y++;
        }
        x++;
    }
    
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}
//gcc -lmlx -framework OpenGL -framework AppKit main.c