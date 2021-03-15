/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:25 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/15 17:16:25 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

//  gcc -lmlx -framework OpenGL -framework AppKit files/*.c && ./a.out
//   gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit files/*.c includes/*.h minilibx/mlx.h && ./a.out

#include <stdio.h>

int             main(void)
{
   
    t_global    a;
    t_imgdata   img;
    t_viewport  vp;
    
    a.mlx = mlx_init();

    setup_window(&a, &img);
    setup_viewport(&vp);

    main_print(&a, &vp, &img);

    mlx_put_image_to_window(a.mlx, a.mlx_win, img.img, 0, 0);

    mlx_loop(a.mlx);
}
