#include "../includes/mini_rt.h"

void            my_mlx_pixel_put(t_imgdata *data, int x, int y, int color)
{
    char    *dst;
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    main_print(t_global a, t_imgdata img)
{
    for (int j = 0; j <= a.width; ++j)
	{
		for (int i = 0; i < a.height; ++i)
		{
			float r = (float)(i) / (float)(a.height);
            float g = (float)(i) / (float)(a.height);             
            float b = 1;
            a.color = create_color(r,g,b);
			my_mlx_pixel_put(&img, j, i, a.color);
        }
    }
}