/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:19 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/15 17:25:52 by liafigli         ###   ########.fr       */
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
    t_triangle tr;
    t_plane pl;
    t_vector norm;

    sph.origin = create_vector(0.0,0.0,-1.5);
    sph.ray = 0.5;

    tr.p1 = create_vector(-1.5, 0.5, -1.7);
    tr.p2 = create_vector(0.40, -0.75, -5.0);
    tr.p3 = create_vector(0.75, 0.36, -1.7);

    pl.center = create_vector(1.0, 0.5, -1.0);
    pl.orientation = create_vector(1.25, 0.75, -1.0);

    a->t = create_sphere(sph, r);
    if(a->t > 0.0)
	{
		a->point = find_point(r, a->t); // Calcola il punto in cui ha colpito la sfera
		sph.color = vec_normalize(vec_div_float(vec_sub(a->point, sph.origin), sph.ray)); //La normale va sempre calcolata per lo shading
		sph.color = vec_sum_float(sph.color, 1.0);
		return vec_per_float(sph.color, 0.5); //Qui stiamo mappando x/y/z a valori RGB per creare il gradient
	}
    a->color = create_vector(1.0, 1.0, 1.0);
	a->color2 = create_vector(0.5, 1.0, 1.0);
	norm = (r.dir); // Mettiamo a norma la direzione del raggio
	a->t = 0.5 * (norm.y + 1.0); // Qui la t ha sempre un range [0, 1]
	return(vec_sum(vec_per_float(a->color, (1.0 - a->t)), vec_per_float(a->color2, a->t)));
}