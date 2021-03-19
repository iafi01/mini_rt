/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:19 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/18 10:55:11 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

t_ray create_ray(t_vector origin, t_vector dir)
{
    t_ray ray;
    ray.origin = origin;
    ray.dir = dir;
    return (ray);
}

// la formula matematica  Pt = tB + A (retta) oppure-> y = mx + p
t_vector find_point(t_ray ray, float t)
{
    return (vec_sum(vec_per_float(ray.dir, t), ray.origin));
}

t_vector ray_color(t_ray r, t_global *a)
{
    t_sphere sph;
	t_plane pl;
	t_triangle tr;
	//t_vector norm_dir;

	sph.origin = create_vector(0.0, 0.0, -0.5);
	sph.ray = 3.5;

	tr.p1 = create_vector(-1.5, 0.5, -1.7);
	tr.p2 = create_vector(0.40, -0.75, -5.0);
	tr.p3 = create_vector(0.75, 0.36, -1.7);
	
	pl.center = create_vector(1.0, 0.5, -1.0);
	pl.orientation = create_vector(1.25, 0.75, -1.0);

	create_sphere(a, sph, r);
	//printf("%f\n",a->t);
	if(a->t > 0.0)
	{	
		return create_vector(0.5,0.7,1.0); 
	}
	return create_vector(1.0,0.0,0.0); 
}