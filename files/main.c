/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:25 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/20 15:00:17 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

//  gcc -lmlx -framework OpenGL -framework AppKit files/*.c && ./a.out
//   gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit files/*.c includes/*.h minilibx/mlx.h && ./a.out

#include <stdlib.h>


int		close_function(const t_global *a)
{
	mlx_clear_window(a->mlx, a->mlx_win);
	mlx_destroy_window(a->mlx, a->mlx_win);
    exit(0);
}

int		key_function(const int keycode, const t_global *a)
{
	if (keycode == 53)
		close_function(a);
	return (0);
}

int             main()
{
   
    t_global    a;
    t_imgdata   img;
    t_viewport  vp;

    //if (argc != 2 && !(argc == 3 && ft_strncmp(argv[2], "save", 4 == 0)))
        //ft_putstr_fd("Error number of params!",1);

    a.mlx = mlx_init();
    setup_window(&a, &img);
    setup_viewport(&vp);

    main_print(&a, &vp, &img);
    mlx_key_hook(a.mlx_win, key_function, &a);

    mlx_put_image_to_window(a.mlx, a.mlx_win, img.img, 0, 0);
    mlx_loop(a.mlx);
}
