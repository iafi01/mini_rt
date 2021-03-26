/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:36 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/26 16:30:37 by liafigli         ###   ########.fr       */
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

	sph.origin = create_p(0.7, 0.0, -2);
	sph.diameter = 0.5;
	//ft_putstr("p\n");
	a->t = create_sphere(a, sph, r);
	//printf("%f\n", a->t);

	if((a->t = create_sphere(a, sph, r)) > 0.0)
	{	
		//ft_putstr("e\n");
		a->point = find_point(r, a->t);
		t_vector color = normalize_v(diff_p_p(a->point, sph.origin));
		return (mult_vec_scal(sum_vec_scal(color, 1.0), 0.5));
	}
	return (create_v(0.0, 1.0, 0.0));
}
