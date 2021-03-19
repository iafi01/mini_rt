/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:37 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/18 10:54:33 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	create_sphere(t_global *a, t_sphere sph, t_ray r)
{

	t_calc	s;
			//printf(":r.origin%d:%d:%d:\n", sph.origin.x,sph.origin.y,sph.origin.z);
	s.sub = vec_sub(r.origin, sph.origin);
			//printf(":%d:%d:%d\n", s.sub.x,s.sub.y,s.sub.z);
			//printf("r.dir:%d:%d:%d\n", r.dir.x,r.dir.y,r.dir.z);

	s.a = vec_dot(r.dir, r.dir);
			//printf(":a%f:\n", s.a);

	s.b = 2 * vec_dot(r.dir, s.sub);
			//printf(":b%f:\n", s.b);

	s.c = vec_dot(s.sub, s.sub) - pow(sph.ray / 2, 2);
			//printf(":c%f:\n", s.c);
			//printf("sph.ray:%f\n", sph.ray);

	
	s.delta = pow(s.b, 2) - (4 * s.a * s.c);
			//printf(":de%f:\n", s.delta);

	if (s.delta < 0)
		return ;
	s.delta = sqrt(s.delta);
	s.a = 2 * s.a;
	s.t1 = (-s.b - s.delta) / s.a;
	s.t2 = (-s.b + s.delta) / s.a;
	//printf("\n::::%f **** %f\n",s.t1,s.t2);
	if (s.t1 >= 0 && a->t > s.t1)
		a->t = s.t1;
	else if (s.t2 >= 0 && a->t > s.t2)
		a->t = s.t2;
}