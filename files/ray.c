/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:36 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/29 17:36:13 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

t_ray create_ray(t_point origin, t_vector direction)
{
	t_ray ray;
	ray.origin = origin;
	ray.dir = direction;
	return(ray);
}

t_point find_point(t_ray ray, float t)
{
    return(sum_p_vec(ray.origin, mult_vec_scal(ray.dir, t)));
}

t_vector ray_color(t_ray r, t_global *a)
{
	t_sphere sph;

	t_vector norm_dir;

	sph.origin = create_p(-1.0, -1.0, -1.5);
	sph.diameter = 0.5;

	a->t = create_sphere(a, sph, r);
	if(a->t > 0.0)
	{
		a->point = find_point(r, a->t);
		t_vector color = normalize_v(div_vec_scal(diff_p_p(a->point, sph.origin), sph.diameter));
		color = sum_vec_scal(color, 1.0);
		return mult_vec_scal(color, 0.5);
	}

	t_vector color1 = create_v(1.0, 1.0, 1.0);
	t_vector color2 = create_v(0.5, 0.7, 1.0);
	norm_dir = normalize_v(r.dir); 
	a->t = 0.5 * (norm_dir.y + 1.0); 
	return(sum_vec_vec(mult_vec_scal(color1, (1.0 - a->t)), mult_vec_scal(color2, a->t)));
}
