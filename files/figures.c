/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:37 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/17 16:15:06 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	create_sphere(t_global *a, t_sphere sph, t_ray r)
{
	t_calc	s;

	s.sub = vec_sub(r.origin, sph.origin);
	s.a = vec_dot(r.dir, r.dir);
	s.b = 2 * vec_dot(r.dir, s.sub);
	s.c = vec_dot(s.sub, s.sub) - pow(sph.ray / 2, 2);
	s.delta = pow(s.b, 2) - (4 * s.a * s.c);
	if (s.delta < 0)
		return ;
	s.delta = sqrt(s.delta);
	s.a = 2 * s.a;
	s.t1 = (-s.b - s.delta) / s.a;
	s.t2 = (-s.b + s.delta) / s.a;
	printf("%f **** %f\n",s.t1,s.t2);
	if (a->t > s.t1)
		a->t = s.t1;
	else if (a->t > s.t2)
		a->t = s.t2;
}