/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 17:10:22 by sdunckel          #+#    #+#             */
/*   Updated: 2021/04/09 10:56:49 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	sphere(t_mini_rt *rt, t_element *sphere, t_vec ori, t_vec dir)
{
	t_solve	s;

	s.sub = vec_sub(ori, sphere->point);
	s.a = vec_dot(dir, dir);
	s.b = 2 * vec_dot(dir, s.sub);
	s.c = vec_dot(s.sub, s.sub) - pow(sphere->diameter / 2, 2);
	s.det = pow(s.b, 2) - (4 * s.a * s.c);
	if (s.det < 0)
		return ;
	s.det = sqrt(s.det);
	s.a = 2 * s.a;
	s.t1 = (-s.b - s.det) / s.a;
	s.t2 = (-s.b + s.det) / s.a;
	if (s.t1 >= 0 && rt->t > s.t1)
		rt->t = s.t1;
	else if (s.t2 >= 0 && rt->t > s.t2)
		rt->t = s.t2;
}
