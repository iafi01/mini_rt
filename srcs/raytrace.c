/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:24:40 by sdunckel          #+#    #+#             */
/*   Updated: 2021/04/09 10:59:54 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	find_objs(t_mini_rt *rt, t_element *obj, t_vec ori, t_vec dir)
{
	if (obj->id == SPHERE)
		sphere(rt, obj, ori, dir);
	else if (obj->id == PLANE)
		plane(rt, obj, ori, dir);
	else if (obj->id == CYLINDER)
		cylinder(rt, obj, ori, dir);
	else if (obj->id == CIRCLE)
		circle(rt, obj, ori, dir);
	else if (obj->id == TRIANGLE)
		triangle(rt, obj, ori, dir);
	else if (obj->id == SQUARE)
		square(rt, obj, ori, dir);
	else if (obj->id == CONE)
		cone(rt, obj, ori, dir);
}

t_color	ray_intersect(t_mini_rt *rt)
{
	t_list		*tmp;

	rt->obj = NULL;
	rt->t = INT_MAX;
	rt->k = INT_MAX;
	ft_bzero(&rt->color, sizeof(t_color));
	if (rt->sky)
		rt->color = get_sky_coord(rt);
	tmp = rt->objs_list;
	while (tmp)
	{
		find_objs(rt, tmp->content, rt->ray.ori, rt->ray.dir);
		if (rt->t > 0 && rt->t < rt->k)
			rt->obj = tmp->content;
		if (rt->t > 0 && rt->t < rt->k)
			rt->k = rt->t;
		tmp = tmp->next;
	}
	if (rt->obj)
	{
		rt->p = vec_add(rt->ray.ori, vec_mul(rt->ray.dir, rt->k));
		rt->color = get_color(rt);
		if (rt->obj->ref)
			reflect(rt);
		rt->color = apply_lights(rt);
	}
	return (rt->color);
}

t_vec	calc_ray(t_mini_rt *rt, float x, float y)
{
	t_vec	dir;
	float	norm_x;
	float	norm_y;
	t_vec	image_point;

	norm_x = ((x / (float)rt->res.x) - 0.5);
	norm_y = ((y / (float)rt->res.y) - 0.5);
	if (rt->res.x < rt->res.y)
		norm_x *= rt->aspect;
	if (rt->res.x > rt->res.y)
		norm_y /= rt->aspect;
	image_point = vec_add(vec_add(vec_add(vec_mul(rt->cam->right, norm_x), \
		vec_mul(rt->cam->up, norm_y)), rt->ray.ori), \
		vec_normalize(rt->cam->orient));
	dir = vec_normalize(vec_sub(image_point, rt->ray.ori));
	return (dir);
}

t_color	anti_aliasing(t_mini_rt *rt, float i, float j)
{
	t_color	color;
	int		aa;
	float	aax;
	float	aay;

	aa = 0;
	aay = -(rt->anti_aliasing - 1) / rt->anti_aliasing;
	ft_bzero(&color, sizeof(t_color));
	while (aa < (pow(rt->anti_aliasing, 2)))
	{
		aax = -(rt->anti_aliasing - 1) / rt->anti_aliasing;
		while (aax <= (rt->anti_aliasing - 1) / rt->anti_aliasing)
		{
			rt->ray.dir = calc_ray(rt, i + aax, j + aay);
			rt->color2 = ray_intersect(rt);
			color = color_add(color, rt->color2, 0);
			aax += 1 / (rt->anti_aliasing - 1);
			aa++;
		}
		aay += 1 / ((float)rt->anti_aliasing - 1);
	}
	color = color_div(color, aa);
	return (color);
}

void	raytracing(t_thread *th)
{
	float	st;

	th->j = 0;
	st = 0;
	if (th->scene.st && th->cur_thr % 2 == 1)
		st = round(th->scene.res.x / 50);
	while (th->j < th->scene.res.y && th->cur_thr >= 0)
	{
		th->i = th->cur_thr;
		th->scene.nbref = 0;
		while (th->i < th->scene.res.x && th->scene.nbref == 0)
		{
			if (th->scene.anti_aliasing > 1)
				th->scene.color = anti_aliasing(&th->scene, th->i, th->j);
			if (th->scene.anti_aliasing <= 1)
				th->scene.ray.dir = calc_ray(&th->scene, th->i - st, th->j);
			if (th->scene.anti_aliasing <= 1)
				th->scene.color = ray_intersect(&th->scene);
			color_put(&th->scene, th->i, th->j);
			th->i += THREAD_COUNT;
		}
		th->scene.percent = (int)(th->j * 100 / th->scene.res.y) + 1;
		th->j++;
	}
	pthread_exit(NULL);
}
