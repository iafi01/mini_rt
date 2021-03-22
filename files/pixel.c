/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:27 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/21 13:10:24 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void            my_mlx_pixel_put(t_imgdata *data, int x, int y, int color)
{
    char    *dst;
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int intersect_circle(t_global *a, int x, int y)
{
    float v = (float)y / a->height;

    x -= a->width / 2;//posizione x nel piano
            x *= x;
            y -= a->height / 2; //posizione y nel piano
            y *= y;
            if (x + y <= 10000) //grandezza cerchio
                return(create_color(v, 0, 0));
            return (create_color(v, v, 0.9));
}

void    main_print(t_global *a, t_viewport *vp, t_imgdata *img)
{
    //t_ray r;

    int j = a->height - 1;
    int i;

    while (j > 0)
    {
        i = 0;
        while (i < a->width)
        {
            vp->origin = create_p(0,0,0);
            //float u = (float)i / a->width;
            //float v = (float)j / a->height;
            int colors = intersect_circle(a, i, j);
            
            
            my_mlx_pixel_put(img, i , j, colors);
            i++;
        }
        j--;
    }
}