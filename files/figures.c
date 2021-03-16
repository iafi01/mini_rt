/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:37 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/16 10:03:42 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

float create_sphere(t_sphere sph, t_ray r)
{
	t_calc s;

	s.sub = vec_sub(r.origin, sph.origin);
	
	s.a = vec_dot(r.dir, r.dir);
	s.b = 2 * vec_dot(r.dir, s.sub);
	s.c = vec_dot(s.sub, s.sub) - pow(sph.ray, 2);
	s.delta = pow(s.b, 2) - (4 * s.a * s.c);
	if(s.delta < 0)
		return -1;
	s.delta = sqrt(s.delta);
	s.a = 2 * s.a;
	s.t1 = (-s.b - s.delta) / s.a;
	s.t2 = (-s.b + s.delta) / s.a;
	if(s.t1 >= 0 && s.t2 > s.t1) 
		s.t2 = s.t1;
	else if(s.t2 >= 0 && s.t1 > s.t2)
		s.t1 = s.t2;
	return(s.t1);
}