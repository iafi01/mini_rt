#include "../includes/mini_rt.h"

//  gcc -lmlx -framework OpenGL -framework AppKit files/*.c && ./a.out

//   gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit files/*.c includes/*.h minilibx/mlx.h && ./a.out

#include <stdio.h>
int             main(void)
{
   
    t_global    a;
    t_imgdata   img;
    t_viewport  vp;
    
    printf("a\n");
    a.mlx = mlx_init();
    printf("b\n");
    setup_window(&a, &img);
    printf("c\n");
    setup_viewport(&vp);
    printf("d\n");
    main_print(&a, &vp, &img);
    printf("e\n");
    mlx_put_image_to_window(a.mlx, a.mlx_win, img.img, 0, 0);
    printf("f\n");
    mlx_loop(a.mlx);
}
