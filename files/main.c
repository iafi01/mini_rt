#include "../includes/mini_rt.h"

//  gcc -lmlx -framework OpenGL -framework AppKit files/*.c && ./a.out


int             main(void)
{
   
    t_global    a;
    t_imgdata   img;
    t_viewport  vp;
    
    //t_sphere sph;
    //t_ray r;

    a.mlx = mlx_init();
    
    setup_window(&a,&vp,&img);
    setup_viewport(&vp);

    main_print(&vp, &img);
    //create_sphere(&a, sph, r);
    mlx_put_image_to_window(a.mlx, a.mlx_win, img.img, 0, 0);
    mlx_loop(a.mlx);
}
