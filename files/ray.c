/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:36 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/29 12:39:59 by liafigli         ###   ########.fr       */
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
#include <stdio.h>
// la formula matematica  Pt = tB + A (retta) oppure-> y = mx + p
t_point find_point(t_ray ray, float t)
{
    return (sum_p_vec(ray.origin, mult_vec_scal(ray.dir, t)));
}

t_vector ray_color(t_ray r, t_global *a)
{
    t_sphere sph;
	sph.origin = create_p(0.7, 0, -2.0);
	sph.diameter = 0.5;
	a->t = create_sphere(a, sph, r);

	if (a->t > 0.0)
	{
		a->point = find_point(r, a->t);
		t_vector v = normalize_v(diff_p_p(a->point, sph.origin));
		return (mult_vec_scal(sum_vec_scal(v, 1.0), 0.5));
	}

	t_vector norm_dir =  normalize_v(r.dir);

	a->t = 0.5 * (norm_dir.y + 1);

	t_vector color1 = create_v(1.0, 1.0, 1.0);
	t_vector color2 = create_v(0.5, 0.7, 0.58);

	return (sum_vec_vec((mult_vec_scal(color1, 1.0 - a->t)), (mult_vec_scal(color2, a->t))));
}
