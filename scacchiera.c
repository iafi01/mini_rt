#include <mlx.h>
typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;
void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}
int             main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    int x;
    int y;
    x = 0;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 500, 500, "IAFI");
    img.img = mlx_new_image(mlx, 500, 500);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    while (x != 500)
    {
        y = 0;
        while (y <= 500)
        {
            if ((y >= 100 && y<=200) || (y >= 300 && y<=400))
            {
                if ((x >= 100 && x<=200) || (x >= 300 && x<=400))
                    my_mlx_pixel_put(&img, x, y, 0x000000FF);
                else if ((x <=100 || x >= 200) && (x<=300 || x >= 400) && x<=500)
                    my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
                y++;
            }
            else if ((y <=100 || y >= 200) && (y<=300 || y >= 400) && y<=500)
            {
                if ((x <=100 || x >= 200) && (x<=300 || x >= 400) && x<=500)
                    my_mlx_pixel_put(&img, x, y, 0x000000FF);
                else if ((x >= 100 && x<=200) || (x >= 300 && x<=400))
                    my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
                y++;
            }
        }
        x++;
    }
    
    
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}
//gcc -lmlx -framework OpenGL -framework AppKit main.c
