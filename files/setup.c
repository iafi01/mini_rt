#include "../includes/mini_rt.h"

void setup_window(t_global *a, t_viewport *vp, t_imgdata *img)
{
    a->width = 1920;
    a->height = 1080;

    a->mlx_win = mlx_new_window(a->mlx, a->width, a->height, "IAFI");
        img->img = mlx_new_image(a->mlx, a->width, a->height);
        img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
                                    &img->endian);
}

void setup_viewport(t_viewport *vp)
{
    vp->lower_left_corner = create_vec(1,1,1);
    vp->hor_axis = create_vec(4,0,0);
    vp->ver_axis = create_vec(0,2,0);
    vp->origin = create_vec(0,0,0);
}