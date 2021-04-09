/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:39:46 by sdunckel          #+#    #+#             */
/*   Updated: 2021/04/09 10:56:49 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

t_color	raiiinbow(t_mini_rt *rt)
{
	t_color		color;
	float		dist;

	dist = (rt->obj->id == PLANE ? fmod(rt->k / 50, 3) : fmod(rt->k / 10, 3));
	if (dist < 1)
		color = (t_color){1, (dist - 0.5) * 2, 1 - dist * 2};
	else if (dist >= 1 && dist < 2)
	{
		dist -= 1;
		color = (t_color){1 - dist * 2, 1, (dist - 0.5) * 2};
	}
	else if (dist >= 2 && dist <= 3)
	{
		dist -= 2;
		color = (t_color){(dist - 0.5) * 2, 1 - dist * 2, 1};
	}
	color.r < 0 || color.r > 1 ? color.r = 0 : 0;
	color.g < 0 || color.g > 1 ? color.g = 0 : 0;
	color.b < 0 || color.b > 1 ? color.b = 0 : 0;
	return (color);
}

void	create_texture(t_mini_rt *rt, t_element *elem, char *file_path)
{
	if (!(elem->tex.ptr = mlx_xpm_file_to_image(rt->mlx_ptr, file_path,
		&elem->tex.width, &elem->tex.height)))
		handle_error("fail creating texture", rt);
	if (!(elem->tex.img = mlx_get_data_addr(elem->tex.ptr, &elem->tex.bpp,
		&elem->tex.size_line, &elem->tex.endian)))
		handle_error("fail creating texture", rt);
}

t_color	get_color(t_mini_rt *rt)
{
	int		i;
	int		column;
	int		row;
	t_color	color;

	i = 0;
	column = 0;
	row = 0;
	if (rt->obj->id == SPHERE && rt->obj->tex.ptr)
	{
		get_tex_coord(rt, rt->obj, &column, &row);
		i = row * rt->obj->tex.size_line + rt->obj->tex.bpp / 8 * column;
		color.b = (float)(unsigned char)rt->obj->tex.img[i] / 255;
		color.g = (float)(unsigned char)rt->obj->tex.img[i + 1] / 255;
		color.r = (float)(unsigned char)rt->obj->tex.img[i + 2] / 255;
	}
	else if (rt->obj->rainbow)
		color = raiiinbow(rt);
	else
		color = rt->obj->color;
	return (color);
}

void	get_tex_coord(t_mini_rt *rt, t_element *sphere, int *column, int *row)
{
	float	u;
	float	v;
	t_vec	n;

	n = vec_normalize(vec_sub(rt->p, sphere->point));
	u = 0.5 + atan2(n.z, n.x) / (2 * M_PI);
	v = 0.5 - asin(n.y) / M_PI;
	*column = (int)(sphere->tex.width * u);
	*row = (int)(sphere->tex.height * v);
}
