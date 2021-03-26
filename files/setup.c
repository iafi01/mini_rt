/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:36 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/25 18:00:45 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void setup_window(t_global *a, t_imgdata *img)
{


    a->mlx_win = mlx_new_window(a->mlx, a->width, a->height, "IAFI");
        img->img = mlx_new_image(a->mlx, a->width, a->height);
        img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
                                    &img->endian);
        a->lower_left_corner = create_p(0, 0, 0.0);
        a->hor_axis = create_v(4.0,0.0,0.0);
        a->ver_axis = create_v(0.0,2.0,0.0);
        a->origin = create_p(0.0,0.0,0.0);
}

void error(char *str)
{
    ft_putstr(str);
    exit(0);
}