/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:24:22 by liafigli          #+#    #+#             */
/*   Updated: 2021/04/08 11:11:58 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	free_camera_and_texture(t_mini_rt *rt)
{
	t_list		*tmp;
	t_camera	*cam;
	t_element	*obj;

	tmp = rt->cam_list;
	while (tmp)
	{
		cam = tmp->content;
		if (cam->img.ptr)
			mlx_destroy_image(rt->mlx_ptr, cam->img.ptr);
		tmp = tmp->next;
	}
	tmp = rt->objs_list;
	while (tmp)
	{
		obj = tmp->content;
		if (obj->tex.img)
			mlx_destroy_image(rt->mlx_ptr, obj->tex.ptr);
		tmp = tmp->next;
	}
}

void	handle_error(char *str, t_mini_rt *rt)
{
    ft_printf(RED,str);
	if (rt->split)
		free_split(rt->split);
	if (rt->line)
		ft_strdel(&rt->line);
	if (rt->sky)
		free_sky(rt);
	free_camera_and_texture(rt);
	ft_lstclear(&rt->objs_list, free);
	ft_lstclear(&rt->cam_list, free);
	ft_lstclear(&rt->light_list, free);
	exit(EXIT_FAILURE);
}