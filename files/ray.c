/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:36 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/25 17:10:59 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

t_ray create_ray(t_point origin, t_vector dir)
{
    t_ray ray;
    ray.origin = origin;
    ray.dir = dir;
    return (ray);
}

// la formula matematica  Pt = tB + A (retta) oppure-> y = mx + p
t_point find_point(t_ray ray, float t)
{
    return (sum_p_vec(ray.origin, mult_vec_scal(ray.dir, t)));
}

int ray_color(t_ray r, t_global *a)
{
    t_sphere sph;

	sph.origin = create_p(0.0, 0.0, -0.5);
	sph.diameter = 3.5;

	create_sphere(a, sph, r);
	if(a->t > 0.0)
	{	
		return (create_color(0.3, 0.3, 0.9));
	}
	return (create_color(0.3, 0.3, 0.9));
}
