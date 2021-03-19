/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:27 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/19 15:25:18 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"
//#include <stdio.h>
void            my_mlx_pixel_put(t_imgdata *data, int x, int y, int color)
{
    char    *dst;
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    main_print(t_global *a, t_viewport *vp, t_imgdata *img)
{
    t_ray r;

    int j = 0;
    int i;

    while (j < a->height - 1)
    {
        i = 0;
        while (i < a->width)
        {
            //r = create_ray();
            vp->origin = create_p(0,0,0);
            //float u = (float)i / a->width;
            float v = (float)j / a->height;
            int colors = create_color(v, v, 0.8);
            my_mlx_pixel_put(img, i , j, colors);
            i++;
        }
        j++;
    }
}