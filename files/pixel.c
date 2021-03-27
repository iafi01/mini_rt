/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:27 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/27 11:57:39 by liafigli         ###   ########.fr       */
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
#include <stdio.h>
float create_sphere(t_global *p, t_sphere sph, t_ray r)
{
    float radius = sph.diameter / 2;
    p->s.sub = diff_p_p(r.origin, sph.origin);
    p->s.a = dot_vec(r.dir, r.dir);
    p->s.b = 2 * dot_vec(r.dir, p->s.sub);
    p->s.c = dot_vec(p->s.sub, p->s.sub) - pow(radius, 2);
    //printf("a:%f-b:%f-c:%f\n", p->s.a,p->s.b,p->s.c);

    p->s.delta = pow(p->s.b, 2) - 4 * p->s.a * p->s.c;
    //printf("delta:%f\n", p->s.delta);
    if (p->s.delta < 0)
    	return (-1);
	else
		return(- p->s.b - (sqrt(p->s.delta)) / p->s.a);
}

void    main_print(t_global *a, t_imgdata *img)
{

    int j = a->height - 1;
    int i;
    int colors;
    t_ray ray;
    t_camera camera;
    while (j > 0)
    {
        i = 0;
        while (i < a->width)
        {
            float u = (float)i / a->width - 1;
            float v = (float)j / a->height - 1;
            ray = create_ray(camera.position, diff_p_p(camera.position ,sum_p_vec(a->lower_left_corner, sum_vec_vec(mult_vec_scal(a->hor_axis, u),mult_vec_scal(a->ver_axis, v)))));
            t_vector cl = ray_color(ray, a);
            colors = create_color(cl.x, cl.y, cl.z);
            my_mlx_pixel_put(img, i , j, colors);
            i++;
        }
        j--;
    }
}