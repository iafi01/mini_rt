/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:36 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/19 11:51:34 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void setup_window(global *a, imgdata *img)
{
    a->width = 2000;
    a->height = 1000;

    a->mlx_win = mlx_new_window(a->mlx, a->width, a->height, "IAFI");
        img->img = mlx_new_image(a->mlx, a->width, a->height);
        img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
                                    &img->endian);
}

void setup_viewport(viewport *vp)
{
    vp->lower_left_corner = create_p(2.5, 2.5, 0.0);
    vp->hor_axis = create_v(4.0,0.0,0.0);
    vp->ver_axis = create_v(0.0,2.0,0.0);
    vp->origin = create_p(0.0,0.0,0.0);
}