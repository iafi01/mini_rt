/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:27 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/15 17:29:42 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void            my_mlx_pixel_put(t_imgdata *data, int x, int y, int color)
{
    char    *dst;
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    main_print(t_global *a, t_viewport *vp, t_imgdata *img)
{
    t_ray r;

    int j = a->height - 1;
    int i;

    while (j > 0)
    {
        i = 0;
        while (i < a->width)
        {
            float u = (float)i / a->width;
            float v = (float)j / a->height - 1;
            r = create_ray(vp->origin, vec_sum(vec_sum(vec_per_float(vp->hor_axis, u),
            vec_per_float(vp->ver_axis, v)), vp->lower_left_corner));
            t_vector temp = ray_color(r, a);
            int colors = create_color(temp.x, temp.y, temp.z);
            my_mlx_pixel_put(img, i , j, colors);
            i++;
        }
        j--;
    }
}