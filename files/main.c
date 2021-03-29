/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:25 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/29 16:55:08 by liafigli         ###   ########.fr       */
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

int             main(int argc, char **argv)
{
   
    t_global    a;
    t_imgdata   img;
    t_camera    camera;
    int         bmp;
    
    ft_bzero(&a, sizeof(t_global)); // Inizializzo tutti gli elementi dello struct a 0
	if(!(a.mlx = mlx_init()))
		ft_putstr("Errore Inizializzazione MiniLibX"); //Questo putstr non funziona per qualche strano motivo
    bmp = 0;
    if (argc != 2 && (argc != 3 || ft_strncmp(argv[2], "--save", 6) != 0))
    {
        ft_putstr("Error number of params!");
        return (0);
    }
    if (argc == 3)
        bmp = 1;

    if (estensione(argv[1]))
        error("Error extension file, i need .rt");
    parse(&a, argv[1], bmp);
    
    setup_window(&a, &img, &camera);

    main_print(&a, &img, &camera);
    mlx_key_hook(a.mlx_win, key_function, &a);

    mlx_put_image_to_window(a.mlx, a.mlx_win, img.img, 0, 0);
    mlx_loop(a.mlx);
}
