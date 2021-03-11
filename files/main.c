#include "../includes/mini_rt.h"

int             main(void)
{
   
    t_global    a;
    t_imgdata   img;
    t_viewport  vp;
    
    a.mlx = mlx_init();
    

    setup_window(&a,&vp,&img);
    setup_viewport(&vp);

    main_print(&a, &vp, &img);

    mlx_put_image_to_window(a.mlx, a.mlx_win, img.img, 0, 0);
    mlx_loop(a.mlx);
}
/*
gcc -lmlx -framework OpenGL -framework AppKit files/main.c files/color.c files/pixel.c files/math.c files/setup.c && ./a.out
*/